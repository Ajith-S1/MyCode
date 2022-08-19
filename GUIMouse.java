import java.awt.*;
import java.awt.event.*;

public class Main extends Frame implements MouseListener, MouseMotionListener {
	Label l,l1,l2;
	Main() {
		addMouseListener(this);
		addMouseMotionListener(this);
		
		l=  new Label();		l.setBounds(50,50,100,150);
		add(l);
		l1=  new Label();		l1.setBounds(200,50,100,150);
		add(l1);
		l2=  new Label();		l2.setBounds(200,150,100,150);
		add(l2);
		 setUndecorated(true);
		setSize(400,400);
		//setOpacity(0.2f);
		setBackground(new Color(238,232,170).brighter());
		setLayout(null);
		setVisible(true); // if false window does not open and the execution terminates if no other frames visible
	}
	public void mouseClicked(MouseEvent e)
	{
		l2.setText("MouseClicked");
		System.out.println(e.getX()+ " " + e.getY());
	}
	public void mouseEntered(MouseEvent e) {
		l.setText("mouseEntered");
	}
	public void mouseExited(MouseEvent e) {
		l.setText("mouseExited");
	}
	public void mouseReleased(MouseEvent e) {
		l.setText("mouseReleased");
	}
	public void mousePressed(MouseEvent e) {
		l.setText("mousePressed");
	}
	public void mouseDragged(MouseEvent e) {
		l1.setText("mouseDragged");
	}
	public void mouseMoved(MouseEvent e) {
		l1.setText("mouseMoved");
	}
	public static void main(String []args)
	{
			new Main();
	}
}
