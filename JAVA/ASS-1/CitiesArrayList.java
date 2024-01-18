//SET A1
import java.util.ArrayList;
import java.util.Scanner;
public class CitiesArrayList
{
       public static void main(String[] args)
       {
           Scanner scanner = new Scanner(System.in);
           ArrayList<String> cities = new ArrayList<>();
       
           System.out.print("Enter the number of cities : ");
           int n = scanner.nextInt();
       
           for (int i=0;i<n;i++)
           {
               System.out.println("Enter the name of city "+(i+1)+" : ");
               String city = scanner.next();
               cities.add(city);
           }
           
           System.out.println();
           System.out.println("The cities in the list are : ");
           for (String city : cities)
           {
               System.out.println(city);
           }
           cities.clear();
           
           System.out.println();
           System.out.println("The cities in the list after removal are : ");
           System.out.println();
       
           for (String city : cities)
           {
               System.out.println(city);
           }
      }
       
}
