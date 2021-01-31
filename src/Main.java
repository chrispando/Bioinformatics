import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
       ReadFile read = new ReadFile("G:\\Bioinformatics\\Sequences.txt");
       List<String> DNA = new ArrayList<String>(read.fileReader());

       bruteForceMotifSearch bf = new bruteForceMotifSearch();
       System.out.println(bf.bruteForceMotifSearch(DNA,100,100,5));
    }

}
