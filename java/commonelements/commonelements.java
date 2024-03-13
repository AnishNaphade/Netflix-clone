import java.util.*; 
public class commonelements {
   public static void main(String[] args) {
      int[] array1 = {7, 1, 2, 3, 6};
      int[] array2 = {3, 5, 7, 6, 5};
      List<Integer> commonElements = new ArrayList<>();
      for (int i = 0; i < array1.length; i++) {
         for (int j = 0; j < array2.length; j++) {
            if (array1[i] == array2[j]) {
               commonElements.add(array1[i]);
               break;
            }
         }
      }
      System.out.println("Common Elements: " + commonElements);
   }
}