package Day4;

import javax.swing.*;
import java.awt.*;


public class GUI1 extends JFrame{
	public static void main(String[] args) {
		new GUI1();
	}
	
	public GUI1() {
		this.setTitle("Máy tính tay");
		this.setSize(300, 400);
		
		JTextField ht = new JTextField("0");
		ht.setEditable(false);
		ht.setFont(new Font("Arial", Font.PLAIN, 40));
		ht.setPreferredSize(new Dimension(0, 80));
		ht.setHorizontalAlignment(JTextField.RIGHT);
		this.add(ht);
		
		JPanel p = new JPanel(new GridLayout(5, 4));
		String btnName[][] = {
				{"CE", "C", "AC", "/"},
				{"7", "8", "9", "x"},
				{"4", "5", "6", "-"},
				{"1", "2", "3", "+"},
				{"+/-", "0", ".", "="}
		};
		
		for (int i = 0; i < btnName.length; i++) {
			for (int j = 0; j < btnName[0].length; j++) {
				JButton bt = new JButton(btnName[i][j]);
				bt.setFont(new Font("Arial", Font.PLAIN, 17));
				if (i == 4 && j == 3) {
					bt.setBackground(new Color(122, 172, 211));
				} else if (i == 0 || j == 3) {
					bt.setBackground(new Color(224, 226, 227));
				} else {
					bt.setBackground(Color.WHITE);
				}
				
				p.add(bt);
			}
		}
		
		this.setLayout(new BorderLayout());
		this.add(ht, BorderLayout.NORTH);
		this.add(p, BorderLayout.CENTER);
		this.setVisible(true);
	}
	
}
