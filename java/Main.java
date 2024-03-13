import java.io.*;
import java.io.File;
class Animal {
    public void Sound() {
        System.out.println("sound");
    }
}

class Dog extends Animal {
    public void Sound() {
        System.out.println("dogsound");
    }
}

public class Main {
    public static void main(String[] args) {
        
        Animal animal = new Animal();
        Animal dog = new Dog();

        animal.Sound(); 
        dog.Sound();    

        
       java.util.Scanner scanner = new java.util.Scanner(System.in);
        System.out.print("Enter the file path: ");
        String filePath = scanner.nextLine();
        scanner.close();

        
        File file = new File(filePath);

        
        if (file.exists()) {
            System.out.println("The file '" + filePath + "' exists.");

            
            if (file.canRead()) {
                System.out.println("The file '" + filePath + "' is readable.");
            } else {
                System.out.println("The file '" + filePath + "' is not readable.");
            }

            
            if (file.canWrite()) {
                System.out.println("The file '" + filePath + "' is writable.");
            } else {
                System.out.println("The file '" + filePath + "' is not writable.");
            }

             
            if (file.isFile()) {
                System.out.println("Type of '" + filePath + "': File");
            }

            
            long fileSize = file.length();
            System.out.println("Size of '" + filePath + "': " + fileSize + " bytes");

        } else {
            System.out.println("The file '" + filePath + "' does not exist.");
        }

    }
}

