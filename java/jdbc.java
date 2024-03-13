import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Scanner;

public class jdbc {
   public class JDBCMain {

    public static void main(String[] args) {

        String url="jdbc:mysql://localhost:3306/jdbc";
        String user="root";
        String pwd="Anish@2004";

        Scanner sc=new Scanner(System.in);
        System.out.println("Enter rollNo: ");
        int rno = sc.nextInt();

        System.out.println("Enter Sname: ");
        String sname = sc.next();

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con=DriverManager.getConnection(url,user,pwd);
            Statement st=con.createStatement();

            String sqlInsert="insert into AIA1 values('"+rno+"','"+sname+"')";
            st.executeUpdate(sqlInsert);
            System.out.println("record inserted successfully");


            String sql="select * from AIA1";
            ResultSet rs= st.executeQuery(sql);
            while(rs.next()) {
                System.out.println("RollNo: "+rs.getInt(1));
                System.out.println("Sname: "+rs.getString(2));

            }
//
//         String sqlupdate="update AIA1 set sname='ABC' where rno=10";
//         st.executeUpdate(sqlupdate);
//         System.out.println("record updated successfully");
//
//
//         String sqldelete="delete from AIA1 where rno=1";
//         st.executeUpdate(sqldelete);
//         System.out.println("record deleted successfully");
//


            con.close();
        }
        catch(Exception ex) {
            System.out.println(ex);
        }

    }

} 
}
