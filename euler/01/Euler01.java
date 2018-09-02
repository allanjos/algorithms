import javax.swing.JFrame;

public class Euler01 {
    public static void main(String args[]) {
        System.out.println("Euler number demonstration graph");

        JFrame frame = new JFrame("Euler demonstration");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.setSize(800, 600);

        EulerPanel eulerPanel = new EulerPanel();

        frame.add(eulerPanel);

        eulerPanel.init();

        frame.setVisible(true);
    }
}