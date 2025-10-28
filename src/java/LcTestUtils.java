import java.io.*;
import java.nio.file.*;
import java.util.*;
import com.google.gson.*;
import com.google.gson.annotations.SerializedName;

class ListNode {
    // Harness fields
    int Val; ListNode Next;
    // LeetCode-friendly aliases
    int val; ListNode next;
    ListNode(int v){ this.Val = v; this.val = v; }
}
class TreeNode {
    // Harness fields
    int Val; TreeNode Left, Right;
    // LeetCode-friendly aliases
    int val; TreeNode left, right;
    TreeNode(int v){ this.Val = v; this.val = v; }
}

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
        m.put("2", cases -> Drivers.driver2(cases));
        m.put("104", cases -> Drivers.driver104(cases));
        m.put("3", cases -> Drivers.driver3_auto(cases));
        m.put("9", cases -> Drivers.driver9(cases));
        m.put("11", cases -> Drivers.driver11(cases));
        m.put("20", cases -> Drivers.driver20(cases));
        m.put("21", cases -> Drivers.driver21(cases));
        m.put("35", cases -> Drivers.driver35(cases));
        m.put("36", cases -> Drivers.driver36(cases));
        m.put("42", cases -> Drivers.driver42(cases));
        m.put("94", cases -> Drivers.driver94(cases));
        m.put("98", cases -> Drivers.driver98(cases));
        m.put("100", cases -> Drivers.driver100(cases));
        m.put("102", cases -> Drivers.driver102(cases));
        m.put("103", cases -> Drivers.driver103(cases));
        m.put("110", cases -> Drivers.driver110(cases));
        m.put("160", cases -> Drivers.driver160(cases));
        m.put("200", cases -> Drivers.driver200(cases));
        m.put("206", cases -> Drivers.driver206(cases));
        m.put("226", cases -> Drivers.driver226(cases));
        m.put("238", cases -> Drivers.driver238(cases));
        m.put("424", cases -> Drivers.driver424(cases));
        m.put("438", cases -> Drivers.driver438(cases));
        m.put("560", cases -> Drivers.driver560(cases));
        m.put("567", cases -> Drivers.driver567(cases));
        m.put("739", cases -> Drivers.driver739(cases));
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
            int[] got = new P1_TwoSum().twoSum_local(nums, target);
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

    private static List<List<Integer>> toListOfIntList(JsonArray arr) {
        List<List<Integer>> out = new ArrayList<>();
        if (arr == null) return out;
        for (int i = 0; i < arr.size(); i++) {
            JsonArray row = arr.get(i).getAsJsonArray();
            List<Integer> r = new ArrayList<>();
            for (int j = 0; j < row.size(); j++) r.add(row.get(j).getAsInt());
            out.add(r);
        }
        return out;
    }

    private static boolean deepEquals2D(List<List<Integer>> a, List<List<Integer>> b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            List<Integer> ra = a.get(i), rb = b.get(i);
            if (ra.size() != rb.size()) return false;
            for (int j = 0; j < ra.size(); j++) if (!Objects.equals(ra.get(j), rb.get(j))) return false;
        }
        return true;
    }

    // --- List helpers ---
    private static ListNode buildList(JsonArray arr) {
        if (arr == null || arr.size() == 0) return null;
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for (int i = 0; i < arr.size(); i++) {
            int v = arr.get(i).getAsInt();
            ListNode n = new ListNode(v);
            tail.Next = n; tail.next = n; // keep aliases
            tail = n;
        }
        return dummy.Next;
    }
    private static int[] listToArray(ListNode head) {
        List<Integer> tmp = new ArrayList<>();
        ListNode p = head;
        while (p != null) {
            tmp.add(p.val);
            p = (p.Next != null ? p.Next : p.next);
        }
        int[] out = new int[tmp.size()];
        for (int i = 0; i < tmp.size(); i++) out[i] = tmp.get(i);
        return out;
    }

    // --- Tree helpers ---
    private static Integer toNullableInt(JsonElement el) {
        if (el == null || el.isJsonNull()) return null;
        return el.getAsInt();
    }

    private static TreeNode buildTree(JsonArray arr) {
        if (arr == null || arr.size() == 0) return null;
        List<Integer> vals = new ArrayList<>(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            vals.add(toNullableInt(arr.get(i)));
        }
        if (vals.get(0) == null) return null;
        TreeNode root = new TreeNode(vals.get(0));
        Queue<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        int i = 1;
        while (!q.isEmpty() && i < vals.size()) {
            TreeNode cur = q.poll();
            if (i < vals.size()) {
                Integer lv = vals.get(i++);
                if (lv != null) {
                    cur.Left = new TreeNode(lv);
                    cur.left = cur.Left; // keep aliases in sync
                    q.add(cur.Left);
                }
            }
            if (i < vals.size()) {
                Integer rv = vals.get(i++);
                if (rv != null) {
                    cur.Right = new TreeNode(rv);
                    cur.right = cur.Right; // keep aliases in sync
                    q.add(cur.Right);
                }
            }
        }
        return root;
    }

    private static char[][] to2DCharArray(JsonArray arr) {
        char[][] result = new char[arr.size()][];
        for (int i = 0; i < arr.size(); i++) {
            JsonArray row = arr.get(i).getAsJsonArray();
            result[i] = new char[row.size()];
            for (int j = 0; j < row.size(); j++) {
                result[i][j] = row.get(j).getAsString().charAt(0);
            }
        }
        return result;
    }

    private static int[] treeToArray(TreeNode root) {
        if (root == null) return new int[0];
        List<Integer> result = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode cur = q.poll();
            if (cur != null) {
                result.add(cur.val);
                q.add(cur.left);
                q.add(cur.right);
            } else {
                result.add(null);
            }
        }
        // Remove trailing nulls
        while (!result.isEmpty() && result.get(result.size() - 1) == null) {
            result.remove(result.size() - 1);
        }
        return result.stream().mapToInt(x -> x == null ? 0 : x).toArray();
    }

    static Result driver104(List<JsonObject> cases) {
        List<Integer> indices = new ArrayList<>();
        boolean okAll = true;
        for (int i = 0; i < cases.size(); i++) {
            JsonObject tc = cases.get(i);
            TreeNode root = buildTree(tc.getAsJsonArray("tree"));
            int want = tc.get("expected").getAsInt();
            int got = P104.run(root);
            if (got != want) okAll = false;
            indices.add(i+1);
        }
        return new Result(indices, okAll);
    }

    static Result driver2(List<JsonObject> cases){
        List<Integer> indices = new ArrayList<>();
        boolean okAll = true;
        for (int i=0;i<cases.size();i++){
            JsonObject tc = cases.get(i);
            ListNode l1 = buildList(tc.getAsJsonArray("l1"));
            ListNode l2 = buildList(tc.getAsJsonArray("l2"));
            int[] want = toIntArray(tc.getAsJsonArray("expected"));
            ListNode res = new P2().new Solution().addTwoNumbers(l1,l2);
            int[] got = listToArray(res);
            if (!Arrays.equals(got, want)) okAll = false;
            indices.add(i+1);
        }
        return new Result(indices, okAll);
    }

    // ==== Additional drivers ====
    static Result driver3(List<JsonObject> cases) {
        List<Integer> idx = new ArrayList<>(); boolean okAll = true;
        for (int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); String s=tc.get("input").getAsString(); int want=tc.get("expected").getAsInt();
            int got = new P3().new Solution().lengthOfLongestSubstring(s);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }
    
    static Result driver3_auto(List<JsonObject> cases) {
        System.out.println("Running problem 3 with multiple solutions:");
        List<Integer> idx = new ArrayList<>();
        boolean allPass = true;
        
        // Solution 1: Main (array-based)
        System.out.println("  Solution 1 (main - array-based):");
        boolean pass1 = true;
        for (int i = 0; i < cases.size(); i++) {
            JsonObject tc = cases.get(i);
            String s = tc.get("input").getAsString();
            int want = tc.get("expected").getAsInt();
            int got = new P3().new Solution().lengthOfLongestSubstring(s);
            if (got != want) {
                System.out.printf("    Case %d: FAIL got=%d expected=%d\n", i+1, got, want);
                pass1 = false;
            }
            idx.add(i + 1);
        }
        System.out.println("    " + (pass1 ? "PASS" : "FAIL"));
        allPass &= pass1;
        
        // Solution 2: HashSet-based  
        System.out.println("  Solution 2 (hashset-based):");
        boolean pass2 = true;
        for (int i = 0; i < cases.size(); i++) {
            JsonObject tc = cases.get(i);
            String s = tc.get("input").getAsString();
            int want = tc.get("expected").getAsInt();
            int got = new P3_alt_hashset().new Solution().lengthOfLongestSubstring(s);
            if (got != want) {
                System.out.printf("    Case %d: FAIL got=%d expected=%d\n", i+1, got, want);
                pass2 = false;
            }
        }
        System.out.println("    " + (pass2 ? "PASS" : "FAIL"));
        allPass &= pass2;
        
        // Solution 3: HashMap-based
        System.out.println("  Solution 3 (hashmap-based):");
        boolean pass3 = true;
        for (int i = 0; i < cases.size(); i++) {
            JsonObject tc = cases.get(i);
            String s = tc.get("input").getAsString();
            int want = tc.get("expected").getAsInt();
            int got = new P3_alt_hashmap().new Solution().lengthOfLongestSubstring(s);
            if (got != want) {
                System.out.printf("    Case %d: FAIL got=%d expected=%d\n", i+1, got, want);
                pass3 = false;
            }
        }
        System.out.println("    " + (pass3 ? "PASS" : "FAIL"));
        allPass &= pass3;
        
        return new Result(idx, allPass);
    }




    static Result driver9(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for (int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); int x=tc.get("input").getAsInt(); boolean want=tc.get("expected").getAsBoolean();
            boolean got=new P9().new Solution().isPalindrome(x);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver11(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for (int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); int[] h=toIntArray(tc.getAsJsonArray("input")); int want=tc.get("expected").getAsInt();
            int got=new P11().new Solution().maxArea(h);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver20(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for (int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); String s=tc.get("input").getAsString(); boolean want=tc.get("expected").getAsBoolean();
            boolean got=new P20().new Solution().isValid(s);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver21(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for (int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); ListNode l1=buildList(tc.getAsJsonArray("l1")); ListNode l2=buildList(tc.getAsJsonArray("l2"));
            int[] want=toIntArray(tc.getAsJsonArray("expected"));
            ListNode gotHead=new P21().new Solution().mergeTwoLists(l1,l2);
            int[] got=listToArray(gotHead);
            if (!Arrays.equals(got,want)) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver42(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); int[] a=toIntArray(tc.getAsJsonArray("input")); int want=tc.get("expected").getAsInt();
            int got=new P42().new Solution().trap(a);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver94(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); TreeNode root=buildTree(tc.getAsJsonArray("tree")); int[] want=toIntArray(tc.getAsJsonArray("expected"));
            List<Integer> ans=new P94().new Solution().inorderTraversal(root);
            int[] got=ans.stream().mapToInt(Integer::intValue).toArray();
            if (!Arrays.equals(got,want)) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver98(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); TreeNode root=buildTree(tc.getAsJsonArray("tree")); boolean want=tc.get("expected").getAsBoolean();
            boolean got=new P98().new Solution().isValidBST(root);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver100(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); TreeNode p=buildTree(tc.getAsJsonArray("p")); TreeNode q=buildTree(tc.getAsJsonArray("q"));
            boolean want=tc.get("expected").getAsBoolean();
            boolean got=new P100().new Solution().isSameTree(p,q);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver102(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); TreeNode root=buildTree(tc.getAsJsonArray("tree"));
            List<List<Integer>> want=toListOfIntList(tc.getAsJsonArray("expected"));
            List<List<Integer>> got=new P102().new Solution().levelOrder(root);
            if (!deepEquals2D(got,want)) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver103(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); TreeNode root=buildTree(tc.getAsJsonArray("tree"));
            List<List<Integer>> want=toListOfIntList(tc.getAsJsonArray("expected"));
            List<List<Integer>> got=new P103().new Solution().zigzagLevelOrder(root);
            if (!deepEquals2D(got,want)) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver110(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); TreeNode root=buildTree(tc.getAsJsonArray("tree")); boolean want=tc.get("expected").getAsBoolean();
            boolean got=new P110().new Solution().isBalanced(root);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver424(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); String s=tc.get("input").getAsString(); int k=tc.get("k").getAsInt(); int want=tc.get("expected").getAsInt();
            int got=new P424().new Solution().characterReplacement(s,k);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver438(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); String s=tc.get("s").getAsString(); String p=tc.get("p").getAsString(); int[] want=toIntArray(tc.getAsJsonArray("expected"));
            List<Integer> ans=new P438().new Solution().findAnagrams(s,p);
            int[] got=ans.stream().mapToInt(Integer::intValue).toArray();
            if (!Arrays.equals(got,want)) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver567(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); String s1=tc.get("s1").getAsString(); String s2=tc.get("s2").getAsString(); boolean want=tc.get("expected").getAsBoolean();
            boolean got=new P567().new Solution().checkInclusion(s1,s2);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver739(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); int[] t=toIntArray(tc.getAsJsonArray("input")); int[] want=toIntArray(tc.getAsJsonArray("expected"));
            int[] got=new P739().new Solution().dailyTemperatures(t);
            if (!Arrays.equals(got,want)) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver35(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); int[] nums=toIntArray(tc.getAsJsonArray("nums")); int target=tc.get("target").getAsInt(); int want=tc.get("expected").getAsInt();
            int got=new P35().new Solution().searchInsert(nums,target);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver36(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); char[][] board=to2DCharArray(tc.getAsJsonArray("board")); boolean want=tc.get("expected").getAsBoolean();
            boolean got=new P36().new Solution().isValidSudoku(board);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver160(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i);
            int intersectVal=tc.has("intersectVal") ? tc.get("intersectVal").getAsInt() : 0;
            
            ListNode headA, headB;
            
            if(intersectVal == 0) {
                // No intersection
                headA = buildList(tc.getAsJsonArray("listA"));
                headB = buildList(tc.getAsJsonArray("listB"));
            } else {
                // Create intersection properly
                JsonArray arrA = tc.getAsJsonArray("listA");
                JsonArray arrB = tc.getAsJsonArray("listB");
                int skipA = tc.get("skipA").getAsInt();
                int skipB = tc.get("skipB").getAsInt();
                
                // Build the shared intersection part first (from skipA onward in listA)
                ListNode intersection = null;
                if (skipA < arrA.size()) {
                    ListNode dummy = new ListNode(0);
                    ListNode tail = dummy;
                    for (int k = skipA; k < arrA.size(); k++) {
                        ListNode n = new ListNode(arrA.get(k).getAsInt());
                        tail.Next = n; tail.next = n;
                        tail = n;
                    }
                    intersection = dummy.Next;
                }
                
                // Build listA up to intersection, then connect
                headA = null;
                if (skipA > 0) {
                    ListNode dummy = new ListNode(0);
                    ListNode tail = dummy;
                    for (int k = 0; k < skipA; k++) {
                        ListNode n = new ListNode(arrA.get(k).getAsInt());
                        tail.Next = n; tail.next = n;
                        tail = n;
                    }
                    tail.Next = intersection; tail.next = intersection;
                    headA = dummy.Next;
                } else {
                    headA = intersection;
                }
                
                // Build listB up to intersection, then connect
                headB = null;
                if (skipB > 0) {
                    ListNode dummy = new ListNode(0);
                    ListNode tail = dummy;
                    for (int k = 0; k < skipB; k++) {
                        ListNode n = new ListNode(arrB.get(k).getAsInt());
                        tail.Next = n; tail.next = n;
                        tail = n;
                    }
                    tail.Next = intersection; tail.next = intersection;
                    headB = dummy.Next;
                } else {
                    headB = intersection;
                }
            }
            Integer want=tc.has("expected") && !tc.get("expected").isJsonNull() ? tc.get("expected").getAsInt() : null;
            ListNode gotNode=new P160().new Solution().getIntersectionNode(headA,headB);
            Integer got=gotNode!=null ? gotNode.val : null;
            if (!Objects.equals(got,want)) okAll=false; 
            idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver200(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); char[][] grid=to2DCharArray(tc.getAsJsonArray("grid")); int want=tc.get("expected").getAsInt();
            int got=new P200().new Solution().numIslands(grid);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver206(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); 
            ListNode head=buildList(tc.getAsJsonArray("head")); 
            int[] want=toIntArray(tc.getAsJsonArray("expected"));
            ListNode gotHead=new P206().new Solution().reverseList(head);
            int[] got=listToArray(gotHead);
            if (!Arrays.equals(got,want)) okAll=false; 
            idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver226(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); TreeNode root=buildTree(tc.getAsJsonArray("root")); int[] want=toIntArray(tc.getAsJsonArray("expected"));
            TreeNode gotRoot=new P226().new Solution().invertTree(root);
            int[] got=treeToArray(gotRoot);
            if (!Arrays.equals(got,want)) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver238(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); int[] nums=toIntArray(tc.getAsJsonArray("nums")); int[] want=toIntArray(tc.getAsJsonArray("expected"));
            int[] got=new P238().new Solution().productExceptSelf(nums);
            if (!Arrays.equals(got,want)) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }

    static Result driver560(List<JsonObject> cases){
        List<Integer> idx=new ArrayList<>(); boolean okAll=true;
        for(int i=0;i<cases.size();i++){
            JsonObject tc=cases.get(i); int[] nums=toIntArray(tc.getAsJsonArray("nums")); int k=tc.get("k").getAsInt(); int want=tc.get("expected").getAsInt();
            int got=new P560().new Solution().subarraySum(nums,k);
            if (got!=want) okAll=false; idx.add(i+1);
        }
        return new Result(idx, okAll);
    }
}
