package Ch4;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Bai1 extends JFrame implements ActionListener {
    Label lb, lb1, lb2, lb3;
    TextField txta, txtb, txtkq;
    Button tinh, reset, thoat;
    Panel pn, pn1, pn2, pn3;
    
    // Phương thức khởi tạo giao diện
    public void GUI() {
         lb = new Label("GIAI PHUONG TRINH BAC NHAT");
         lb1 = new Label("Nhap a:");
         lb2 = new Label("Nhap b:");
         lb3 = new Label("Ket qua:");
         
         txta = new TextField(7);
         txtb = new TextField(7);
         txtkq = new TextField();
         txtkq.setEditable(false);
         
         tinh = new Button("Tinh");
         reset = new Button("Reset");
         thoat = new Button("Thoat");
         
         tinh.addActionListener(this);
         reset.addActionListener(this);
         thoat.addActionListener(this);
        
         pn = new Panel(new GridLayout(3, 1));
         pn1 = new Panel(new FlowLayout());
         pn2 = new Panel(new GridLayout(3, 2));
         pn3 = new Panel(new GridLayout(1, 3));
        
         pn1.add(lb);
        
         pn2.add(lb1);
         pn2.add(txta);
         pn2.add(lb2);
         pn2.add(txtb);
         pn2.add(lb3);
         pn2.add(txtkq);
        
         pn3.add(tinh);
         pn3.add(reset);
         pn3.add(thoat);
         
         pn.add(pn1);
         pn.add(pn2);
         pn.add(pn3);
         
         add(pn);
         setSize(400, 300);
         setVisible(true);
    }

    // Xử lý các sự kiện từ các nút bấm
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == tinh) {
            try {
                double a = Double.parseDouble(txta.getText());
                double b = Double.parseDouble(txtb.getText());
                if(a != 0) {
                    txtkq.setText(Double.toString(-b / a));
                } else {
                    if(b == 0)
                        txtkq.setText("Phuong trinh co vo so nghiem");
                    else
                        txtkq.setText("Phuong trinh vo nghiem");
                }
            } catch (NumberFormatException ex) {
                txtkq.setText("Nhap so thuc hop le cho a va b");
            }
        }
        else if(e.getSource() == reset) {
            txta.setText("");
            txtb.setText("");
            txtkq.setText("");
        }
        else if(e.getSource() == thoat) {
            System.exit(0);
        }
    }

    // Constructor: gọi constructor của lớp cha, khởi tạo giao diện và xử lý đóng cửa sổ
    public Bai1(String st) {
        super(st);
        GUI();
        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }
    
    public static void main(String[] args) {
        new Bai1("Giai phuong trinh bac nhat");
    }
}
