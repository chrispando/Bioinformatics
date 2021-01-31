import java.util.List;

public class bruteForceMotifSearch {
    public int Score(List<String>DNA, String s)
    {
        int Score = 0;
       for(int i=0;i<DNA.size();i++)
       {
           for(int j=0;j<DNA.get(i).length()-s.length()+1;j++)
           {
              String s2 = DNA.get(i).substring(j,j+s.length());
                if(s.equals(s2))
                {
                  Score +=1;
                }


           }

       }
        return Score;

    }

    public String bruteForceMotifSearch(List<String> DNA, int t, int n, int l)
    {
        int bestScore = 0;
        String bestMotif = "";

        for(int i=0;i<DNA.size();i++)
        {
            for(int j=0;j<DNA.get(i).length()-l+1;j++)
            {
                String s = DNA.get(i).substring(j,j+l);
                int score = Score(DNA,s);
                if(score> bestScore)
                {
                    bestScore = score;
                    bestMotif = s;
                }
            }
        }

        return  bestMotif;
    }

}
