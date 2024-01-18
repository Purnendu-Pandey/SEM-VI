//SET B2
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class SortHashMap
{
       public static void main(String[] args)
       {
              Map<String,Integer>details = new HashMap<>();
              
              details.put("Sankalp",21);
              details.put("Rajesh",19);
              details.put("Ankit",20);
              details.put("Harshit",60);
              details.put("Pratiksha",23);
              
              System.out.println("The details before sorting are : ");
              
              for (Map.Entry<String,Integer> entry : details.entrySet())
              {
                   System.out.println(entry.getKey()+" - "+entry.getValue());
              }
              
              Map<String,Integer> sortedDetails = new TreeMap<>(details);
              
              System.out.println("\nThe details after sorting are : ");
              
              for (Map.Entry<String,Integer> entry : sortedDetails.entrySet())
              {
                 System.out.println(entry.getKey()+" - "+entry.getValue());
              }
              
       }
}
