import java.io.*;
import java.util.*;

public class ReadFile {
    String fileName;
    public ReadFile(String fileName)
    {
        this.fileName=fileName;
    }

    public List<String> fileReader() throws IOException {
        List<String> DNA = new ArrayList<String>();

        int i=0;
        File file = new File(fileName);
        try {

            BufferedReader br = new BufferedReader(new FileReader(file));

            String st;
            while ((st = br.readLine()) != null)
                DNA.add(st);
        }
        catch(Exception e) {
            System.out.println("Error!");
        }


        return DNA;
    }


}
