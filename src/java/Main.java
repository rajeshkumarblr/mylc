import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        String category = System.getenv("LC_CATEGORY");
        String probNum = System.getenv("LC_PROB_NUM");

        Map<String, Problem> registry = Registry.build();
        ProblemsData tests = ProblemsData.loadFromFile();

        if (category != null && !category.isEmpty()) {
            Runner.runByCategory(registry, tests, category);
            return;
        }

        if (probNum != null && !probNum.isEmpty()) {
            if (probNum.equals("all")) {
                Runner.runAll(registry, tests);
            } else {
                Runner.runOne(registry, tests, probNum);
            }
            return;
        }

        Runner.runAll(registry, tests);
    }
}
