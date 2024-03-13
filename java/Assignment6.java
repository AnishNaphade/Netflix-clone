

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.awt.event.ActionEvent;



    
    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    GUI window = new GUI();
                    window.frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }


    public GUI() {
        initialize();
    }

    /**
     * Initialize the contents of the frame.
     */
    

public class UpdateStud {
    String driverName = "com.mysql.cj.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/jdbc";
    static final String USER = "root";
    static final String PASS = "Anish@2004";
    public void updateTableData() {

        try {
            Connection conn = DriverManager.getConnection(DB_URL,USER,PASS);
            InputDialogInFrame frame = new InputDialogInFrame();
            String m1 = JOptionPane.showInputDialog(frame, "Enter rollNo to update a record");
            if(m1.isEmpty()){
                frame.closeIt();
            }
            String m = JOptionPane.showInputDialog(frame, "New value for Student name");
            if(m.isEmpty()){
                frame.closeIt();
            }
            String usql = "update studData set sname=? WHERE roll =?";
            java.sql.PreparedStatement pst = conn.prepareStatement(usql);
            pst.setString(1,m);
            pst.setString(2,m1);
            pst.executeUpdate();
            JOptionPane.showMessageDialog(null, "record updated");
        } catch (SQLException e ) {
            JOptionPane.showMessageDialog(null, e);

        }
    }}
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import javax.swing.JOptionPane;

public class DeleteStud {
    String driverName = "com.mysql.cj.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/jdbc";
    static final String USER = "root";
    static final String PASS = "Anish@2004";
    public void deleteTableData() {

        try {
            Connection conn = DriverManager.getConnection(DB_URL,USER,PASS);
            InputDialogInFrame frame = new InputDialogInFrame();
            String m = JOptionPane.showInputDialog(frame, "Enter RollNo to delete a record");
            if(m.isEmpty()){
                frame.closeIt();
            }

            String usql = "delete from studData WHERE roll =?";
            java.sql.PreparedStatement pst = conn.prepareStatement(usql);
            pst.setString(1,m);
            pst.executeUpdate();
            JOptionPane.showMessageDialog(null, "record deleted");
        } catch (SQLException e ) {
            JOptionPane.showMessageDialog(null, e);

        }
    }}
import java.awt.BorderLayout;
import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

//import com.mysql.jdbc.PreparedStatement;

public class Display {


    String driverName = "com.mysql.cj.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/jdbc";
    static final String USER = "root";
    static final String PASS = "Anish@2004";
    public void showTableData() {

        JFrame frame1 = new JFrame("Database Result");
        JTable table;
        PreparedStatement pst;
        String[] columnNames = {"Roll No","Student Name" ,"Class"};

        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame1.setLayout(new BorderLayout());
        DefaultTableModel model = new DefaultTableModel();

        model.setColumnIdentifiers(columnNames);

        table = new JTable();

        table.setModel(model);

        table.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);

        table.setFillsViewportHeight(true);

        JScrollPane scroll = new JScrollPane(table);

        scroll.setHorizontalScrollBarPolicy(

                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

        scroll.setVerticalScrollBarPolicy(

                JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);

        try {
            Class.forName(driverName);
            Connection con = DriverManager.getConnection(DB_URL,USER,PASS);
            String sql = "select * from studData";
            Statement ps =  con.createStatement();
            ResultSet rs = ps.executeQuery(sql);

            int i = 0;
            while(rs.next())
            {
                int roll = rs.getInt(2);
                String sname =rs.getString(1);
                String class1 =rs.getString(3);

                model.addRow(new Object[]{roll,sname,class1 });
                i++;
            }
            if(i <1)
            {
                JOptionPane.showMessageDialog(null, "No Record Found","Error",
                        JOptionPane.ERROR_MESSAGE);
            }
            if(i ==1)
            {
                System.out.println(i+" Record Found");
            }
            else
            {
                System.out.println(i+" Records Found");
            }

        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
        frame1.add(scroll);
        frame1.setVisible(true);
        frame1.setSize(400,300);
    }

}
import java.awt.Color;
        import javax.swing.JFrame;
        import javax.swing.JOptionPane;

public class InputDialogInFrame extends JFrame{

    /**
     *
     */
    //private static final long serialVersionUID = 1L;

    public InputDialogInFrame() {

        getContentPane().setBackground(Color.DARK_GRAY);
        setTitle("Input Dialog in Frame");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        setResizable(false);
        setSize(400, 300);
        getContentPane().setLayout(null);

    }

    void closeIt(){

        this.getContentPane().setVisible(false);
        this.dispose();

    }


}
