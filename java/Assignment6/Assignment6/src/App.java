import java.util.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.*;
import  javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;


public class App extends Frame implements ActionListener {
	JButton add1=new JButton("Add");
	JButton update=new JButton("Update");
	JButton delete=new JButton("Delete");
	JTextField r=new JTextField();
	JTextField n=new JTextField();
	App() {
		JFrame f=new JFrame();
		JLabel l=new JLabel("Student Details");
		JLabel roll=new JLabel("Roll Number");
		JLabel name=new JLabel("Name");
		l.setBounds(425, 50, 150, 30);
		name.setBounds(50, 150, 150, 50);
		n.setBounds(250, 150, 150, 30);
		roll.setBounds(50, 200, 150, 50);
		r.setBounds(250, 200, 150, 30);
		add1.setBounds(137, 400, 150, 30);
		update.setBounds(424, 400, 150, 30);
		delete.setBounds(711, 400, 150, 30);
		f.setSize(1000, 1000);
		f.add(l);
		f.add(name);
		f.add(n);
		f.add(roll);
		f.add(r);
		f.add(add1);
		f.add(update);
		f.add(delete);
		f.setLayout(null);
		f.setVisible(true);
		f.getContentPane().setBackground(Color.lightGray);
		
		add1.addActionListener(this);
		update.addActionListener(this);
		delete.addActionListener(this);
		
	}
	public void actionPerformed(ActionEvent e) {
		Scanner sc=new Scanner(System.in);
		String command=e.getActionCommand();
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection conn= DriverManager.getConnection("jdbc:mysql://localhost:3306/java","root","gojim");
			Statement st=conn.createStatement();
			int r1=Integer.parseInt(r.getText());
			String n1=n.getText();
			String url = null;
			if (command.equals("Add")) {
				url="insert into students values ("+r1+",'"+n1+"')";
			}
			else if (command.equals("Update")) {
				url="update students set name='"+n1+"' where rollno="+r1;
			}
			else
			{
				url="delete from students where rollno="+r1;
			}
			st.executeUpdate(url);
			ResultSet r=st.executeQuery("select * from students");
			while (r.next()) {
				System.out.println(r.getString(1)+":"+r.getString(2));
			}
			conn.close();
		}
		catch (Exception e1) {
			System.out.println(e1);
		}
	}
	public static void main(String args[]){
		new App();
	}
}