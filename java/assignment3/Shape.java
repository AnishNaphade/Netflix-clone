import java.util.Scanner;

public class Shape {
    double area;

    void setArea() {
        // Default implementation
        System.out.println("Shape's area cannot be calculated with given inputs.");
    }

    void getInputs() {
        // Default implementation
        System.out.println("No specific inputs needed for this shape.");
    }
}

class Triangle extends Shape {
    double base, height;

    @Override
    void setArea() {
        area = 0.5 * base * height;
    }

    @Override
    void getInputs() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the base of the triangle: ");
        base = scanner.nextDouble();
        System.out.print("Enter the height of the triangle: ");
        height = scanner.nextDouble();
    }
}

class Square extends Shape {
    double side;

    @Override
    void setArea() {
        area = side * side;
    }

    @Override
    void getInputs() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the side length of the square: ");
        side = scanner.nextDouble();
    }
}

class Circle extends Shape {
    double radius;

    @Override
    void setArea() {
        area = Math.PI * radius * radius;
    }

    @Override
    void getInputs() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        radius = scanner.nextDouble();
    }
}

public class Tester {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Select a shape to calculate area:");
            System.out.println("1. Triangle");
            System.out.println("2. Square");
            System.out.println("3. Circle");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            Shape shape = null;

            switch (choice) {
                case 1:
                    shape = new Triangle();
                    break;
                case 2:
                    shape = new Square();
                    break;
                case 3:
                    shape = new Circle();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please select again.");
            }

            if (shape != null) {
                shape.getInputs();
                shape.setArea();
                System.out.println("Area of the shape: " + shape.area);
            }
        } while (choice != 4);
    }
}