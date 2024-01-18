//SET A3
import java.util.TreeSet;
public class ColorTreeSet
{
       public static void main(String[] args)
       {
              TreeSet<String> colors = new TreeSet<>(); 
              colors.add("red");
              colors.add("green");
              colors.add("blue");
              colors.add("yellow");
              colors.add("orange");
              
              System.out.println("The colors in the TreeSet are : ");
              
              for (String color : colors)
              {
                  System.out.println(color);
              }
       }
}

/*
import java.util.Scanner;
import java.util.TreeSet;
public class ColorTreeSet 
{
    public static void main(String[] args) 
    {
       Scanner scanner = new Scanner(System.in);
       TreeSet<String> colors = new TreeSet<>();

       System.out.print("Enter the number of colors: ");
       int n = scanner.nextInt();

       for (int i = 0; i < n; i++) 
       {
            System.out.print("Enter color: ");
            String color = scanner.next();
            colors.add(color);
       }

       System.out.println("Colors in the TreeSet:");
       for (String color : colors) 
       {
            System.out.println(color);
       }
    }
}
*/