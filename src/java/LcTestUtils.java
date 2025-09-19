import java.io.*;
import java.nio.file.*;
import java.util.*;
import com.google.gson.*;
import com.google.gson.annotations.SerializedName;

class ListNode { int Val; ListNode Next; ListNode(int v){Val=v;} }
class TreeNode { int Val; TreeNode Left, Right; TreeNode(int v){Val=v;} }

class ProblemTest {
    @SerializedName("category") String Category;
    @SerializedName("description") String Description;
    @SerializedName("cases") List<JsonObject> Cases;
}

class ProblemsData {
    Map<String, ProblemTest> problems;

    static ProblemsData loadFromFile() throws IOException {
        String root = System.getenv("REPO_ROOT");
        Path p = (root!=null && !root.isEmpty()) ? Paths.get(root, "testcases.json") : Paths.get("testcases.json");
        String json = Files.readString(p);
        Gson gson = new Gson();
        ProblemsData pd = new ProblemsData();
        // testcases.json is a map from id -> spec
        pd.problems = gson.fromJson(json, new com.google.gson.reflect.TypeToken<Map<String, ProblemTest>>(){}.getType());
        return pd;
    }
}

interface Problem {
    // run the test cases and return (indices, allPass)
    Result run(List<JsonObject> cases);
}

class Result { List<Integer> indices; boolean ok; Result(List<Integer> i, boolean k){indices=i; ok=k;} }

class Registry {
    static Map<String, Problem> build() {
        Map<String, Problem> m = new HashMap<>();
        m.put("1", cases -> Drivers.driver1(cases));
        return m;
    }
}

class Runner {
    static void printSummary(List<Row> rows){
        rows.sort(Comparator.comparingInt(r -> r.num));
        System.out.printf("%-4s %-25s %-15s %-6s %s\n", "No", "Description", "Category", "Result", "Cases");
        int passed=0;
        for(Row r: rows){
            System.out.printf("%-4d %-25s %-15s %-6s %s\n", r.num, r.desc, r.category, r.result, r.cases);
            if ("PASS".equals(r.result)) passed++;
        }
        int failed = rows.size()-passed;
        int totalCases = rows.stream().mapToInt(r->r.cases.size()).sum();
        System.out.printf("\nSummary: problems=%d, passed=%d, failed=%d, total_cases=%d\n", rows.size(), passed, failed, totalCases);
        System.out.println("Final Result: "+(failed==0?"PASS yes":"FAIL"));
        if (failed!=0) System.exit(1);
    }

    static void runAll(Map<String, Problem> reg, ProblemsData tests){
        List<Row> rows = new ArrayList<>();
        for (var e: tests.problems.entrySet()){
            String id = e.getKey();
            ProblemTest t = e.getValue();
            Problem p = reg.get(id);
            if (p==null){ rows.add(Row.noFunc(id, t)); continue; }
            Result r = p.run(t.Cases);
            rows.add(Row.from(id, t, r));
        }
        printSummary(rows);
    }
    static void runByCategory(Map<String, Problem> reg, ProblemsData tests, String cat){
        List<Row> rows = new ArrayList<>();
        for (var e: tests.problems.entrySet()){
            String id = e.getKey();
            ProblemTest t = e.getValue();
            if (!cat.equals(t.Category)) continue;
            Problem p = reg.get(id);
            if (p==null){ rows.add(Row.noFunc(id, t)); continue; }
            Result r = p.run(t.Cases);
            rows.add(Row.from(id, t, r));
        }
        printSummary(rows);
    }
    static void runOne(Map<String, Problem> reg, ProblemsData tests, String id){
        List<Row> rows = new ArrayList<>();
        ProblemTest t = tests.problems.get(id);
        if (t==null){
            System.out.println("No such problem in testcases.json: "+id);
            System.exit(2);
        }
        Problem p = reg.get(id);
        if (p==null){ rows.add(Row.noFunc(id, t)); printSummary(rows); return; }
        Result r = p.run(t.Cases);
        rows.add(Row.from(id, t, r));
        printSummary(rows);
    }
}

class Row{
    int num; String desc; String category; String result; List<Integer> cases;
    Row(int n,String d,String c,String r,List<Integer> cs){num=n;desc=d;category=c;result=r;cases=cs;}
    static Row from(String id, ProblemTest t, Result r){
        int n = Integer.parseInt(id);
        String desc = t.Description != null ? t.Description : "";
        return new Row(n, desc, t.Category, r.ok?"PASS":"FAIL", r.indices);
    }
    static Row noFunc(String id, ProblemTest t){
        int n = Integer.parseInt(id);
        String desc = t.Description != null ? t.Description : "";
        return new Row(n, desc, t.Category, "NoFunc", List.of());
    }
}

// Removed custom JSON helper; Gson handles parsing.

class Drivers {
    static Result driver1(List<JsonObject> cases) {
        List<Integer> indices = new ArrayList<>();
        boolean okAll = true;
        for (int i = 0; i < cases.size(); i++) {
            JsonObject tc = cases.get(i);
            int[] nums = toIntArray(tc.getAsJsonArray("input"));
            int target = tc.get("target").getAsInt();
            int[] want = toIntArray(tc.getAsJsonArray("expected"));
            int[] got = new Solution().twoSum(nums, target);
            if (!Arrays.equals(got, want)) {
                okAll = false;
            }
            indices.add(i+1);
        }
        return new Result(indices, okAll);
    }

    private static int[] toIntArray(JsonArray arr) {
        if (arr == null) return new int[0];
        int[] a = new int[arr.size()];
        for (int i = 0; i < arr.size(); i++) a[i] = arr.get(i).getAsInt();
        return a;
    }
}
