package Ch4;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Bai2 extends JFrame implements ActionListener {
    // Labels
    private JLabel lbTitle = new JLabel("Basic Arithmetic Operations", JLabel.CENTER);
    private JLabel lbNum1  = new JLabel("Number 1:");
    private JLabel lbNum2  = new JLabel("Number 2:");
    private JLabel lbRes   = new JLabel("Result:");

    // Text fields
    private JTextField txtNum1 = new JTextField(10);
    private JTextField txtNum2 = new JTextField(10);
    private JTextField txtRes  = new JTextField(12);

    // Buttons
    private JButton btnAdd = new JButton("Addition");
    private JButton btnSub = new JButton("Subtraction");
    private JButton btnMul = new JButton("Multiplication");
    private JButton btnDiv = new JButton("Division");
    private JButton btnReset = new JButton("Reset");
    private JButton btnExit  = new JButton("Exit");

    public Bai2() {
        super("Arithmetic Operations");
        // 1) Tiêu đề
        lbTitle.setFont(lbTitle.getFont().deriveFont(Font.BOLD, 16f));
        JPanel pnlTitle = new JPanel(new BorderLayout());
        pnlTitle.add(lbTitle, BorderLayout.CENTER);

        // 2) Nhập liệu
        txtRes.setEditable(false);
        JPanel pnlInput = new JPanel(new GridLayout(3, 2, 5, 5));
        pnlInput.add(lbNum1);  pnlInput.add(txtNum1);
        pnlInput.add(lbNum2);  pnlInput.add(txtNum2);
        pnlInput.add(lbRes);   pnlInput.add(txtRes);

        // 3) Các phép toán
        JPanel pnlOps = new JPanel(new GridLayout(1, 4, 5, 5));
        pnlOps.add(btnAdd);
        pnlOps.add(btnSub);
        pnlOps.add(btnMul);
        pnlOps.add(btnDiv);

        // 4) Reset & Exit
        JPanel pnlCtrl = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 0));
        pnlCtrl.add(btnReset);
        pnlCtrl.add(btnExit);

        // 5) Panel chính
        JPanel main = new JPanel();
        main.setLayout(new BoxLayout(main, BoxLayout.Y_AXIS));
        main.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        main.add(pnlTitle);
        main.add(Box.createVerticalStrut(10));
        main.add(pnlInput);
        main.add(Box.createVerticalStrut(10));
        main.add(pnlOps);
        main.add(Box.createVerticalStrut(10));
        main.add(pnlCtrl);

        add(main);

        // Đăng ký sự kiện
        btnAdd.addActionListener(this);
        btnSub.addActionListener(this);
        btnMul.addActionListener(this);
        btnDiv.addActionListener(this);
        btnReset.addActionListener(this);
        btnExit.addActionListener(this);

        // Thiết lập JFrame
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 300);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();
        if (src == btnExit) {
            System.exit(0);
            return;
        }
        if (src == btnReset) {
            txtNum1.setText("");
            txtNum2.setText("");
            txtRes.setText("");
            txtNum1.requestFocus();
            return;
        }
        // Phép toán
        try {
            double a = Double.parseDouble(txtNum1.getText().trim());
            double b = Double.parseDouble(txtNum2.getText().trim());
            double r = 0;
            if (src == btnAdd) {
                r = a + b;
            } else if (src == btnSub) {
                r = a - b;
            } else if (src == btnMul) {
                r = a * b;
            } else if (src == btnDiv) {
                if (b == 0) {
                    txtRes.setText("Cannot divide by zero");
                    return;
                }
                r = a / b;
            }
            txtRes.setText(Double.toString(r));
        } catch (NumberFormatException ex) {
            txtRes.setText("Enter valid numbers");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Bai2::new);
    }
}
