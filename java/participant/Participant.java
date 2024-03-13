class Melange {

    private static int counter;
    private String regid;
    private String name;
    private long contactnum;
    private String branch;

    static {
        counter = 1001;
    }

    Melange(String name, long contactnum, String branch) {
        this.name = name;
        this.contactnum = contactnum;
        this.branch = branch;
        regid = "D" + counter;
        Melange.counter++;
    }

    public String getname() {
        return name;
    }

    public void setname(String name) {
        this.name = name;
    }

    public long getcontactnum() {
        return contactnum;
    }

    public void setcontactnum(long contactnum) {
        this.contactnum = contactnum;
    }

    public String getbranch() {
        return branch;
    }

    public void setbranch(String branch) {
        this.branch = branch;
    }

    public String getregid() {
        return regid;
    }

}

public class Participant {
    public static void main(String[] args) {
        Melange student1 = new Melange("Rohit", 1234567889, "Computer");
        Melange student2 = new Melange("Sayali", 1988612300, "Mechanical");
        Melange student3 = new Melange("Anish", 1341678967, "AI&DS");

        System.out.println("Hi " + student1.getname() + "! Your registration id is " + student1.getregid());
        System.out.println("Hi " + student2.getname() + "! Your registration id is " + student2.getregid());
        System.out.println("Hi " + student3.getname() + "! Your registration id is " + student3.getregid());
    }
}
