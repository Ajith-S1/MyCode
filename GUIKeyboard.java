import java.awt.*;
import java.awt.event.*;
public class GUIK extends Frame implements KeyListener {
		Label l,l1;
		String msg ="";
		GUIK(){
		addKeyListener(this);
		l=new Label();
		l1 = new Label();
		l.setBounds(10,10,100,150);
		l1.setBounds(10,90,200,400);
		add(l);
		add(l1);
		//l.CENTER = 10; final var
		setSize(400,400);
		setLayout(null);
		setBackground(new Color(255).brighter());
		setVisible(true);
}
public void keyPressed(KeyEvent ke) {
		l.setText("Key Down");
		int key = ke.getKeyCode();
		switch(key) {
		//Virtual key codes present in KeyEvent class Pg no. 645 text book
		case KeyEvent.VK_F1:
		msg = "<F1>"; break;
		case KeyEvent.VK_F2:
		msg = "<F2>"; break;
		case KeyEvent.VK_PAGE_DOWN: msg = "<PgDn>"; break;
		case KeyEvent.VK_PAGE_UP:
		msg = "<PgUp>";
		break;
		case KeyEvent.VK_LEFT:
		msg = "<Left Arrow>"; break;
		case KeyEvent.VK_RIGHT:
		msg = "<Right Arrow>"; break;
		}
		l1.setText(msg);
}
	public void keyReleased(KeyEvent ke) {
		l.setText("KeyReleased");
	}
	public void keyTyped(KeyEvent ke) {
		msg = msg + ke.getKeyChar();
		l1.setText(msg);
	}

	public static void main(String[] args) {
			new GUIK(); 
	}
}
