//SET A4
import java.util.HashMap;
import java.util.Map;
public class ContactHashTable
{
       public static void main(String[] args)
       {
              Map<String,String> contacts = new HashMap<>();
              
              contacts.put("8305678311","Prasad");
              contacts.put("2349730961","Sankalp");
              contacts.put("9730966860","Ankit");
              contacts.put("9737971953","Harshada");
              contacts.put("8976543245","Sanskriti");
              
              System.out.println("The contacts list is : ");
              for (Map.Entry<String,String> contact : contacts.entrySet())
              {
                   System.out.println(contact.getKey()+" - "+contact.getValue());
              }
       }
}
