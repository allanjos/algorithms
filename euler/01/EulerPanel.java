import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Point;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JPanel;

class EulerPanel extends JPanel implements MouseListener
{
    private double graphMargin = 50.0;
    private List<Point2D> graphPoints = new ArrayList<>();
    private Font font = null;

    public EulerPanel()
    {
        font = new Font("Serif", Font.PLAIN, 18);

        calculatePoints();

        this.addMouseListener(this);
    }

    public void init() {
        //getGraphics().setFont(font);
    }

    public void calculatePoints() {
        graphPoints.clear();

        int n = 200;

        for (int i = 0; i < n; i++) {
            double y = Math.pow((double) 1 + (double) 1 / (double) i, (double) i) * 100.0;

            Point2D point = new Point2D.Double((double) i, y);

            graphPoints.add(point);

            System.out.println("x, y: " + point.getX() + ", " + point.getY());
        }
    }

    public void paintComponent(Graphics g)
    {
        System.out.println("paintComponent()");

        Graphics2D g2d = (Graphics2D) g;

        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        // Background

        g2d.setColor(Color.WHITE);
        g2d.fillRect(0, 0, (int) getSize().getWidth(), (int) getSize().getHeight());

        g2d.setColor(Color.BLACK);

        Shape shape;

        //g2d.setFont(font);

        // Title

        g2d.drawString("Euler constant demonstration", 5, 20);

        // Ruler lines

        shape = new Line2D.Double(graphMargin,
                                  graphMargin,
                                  getSize().width - graphMargin,
                                  graphMargin);

        g2d.draw(shape);

        shape = new Line2D.Double(graphMargin,
                                  graphMargin,
                                  graphMargin,
                                  getSize().height - graphMargin);

        g2d.draw(shape);

        // Legends

        int y = 0;

        while (y * 100 < getSize().height) {
            shape = new Line2D.Double(5,
                                      graphMargin,
                                      5,
                                      getSize().height - graphMargin);

            g.drawString(String.format("%d", y), 5, y * 100);

            System.out.println("legend y = " + y);

            y += 1;
        }

        // Main graph

        g.setColor(Color.BLUE);

        for (int i = 0; i < graphPoints.size(); i++) {
            if (i == 0) {
                System.out.println("Skipping...");
                continue;
            }

            shape = new Line2D.Double(graphPoints.get(i - 1).getX() + graphMargin,
                                      graphPoints.get(i - 1).getY(),
                                      graphPoints.get(i).getX() + graphMargin,
                                      graphPoints.get(i).getY());

            g2d.draw(shape);
        }
    }

    public void mousePressed(MouseEvent e) {
        System.out.println("Mouse pressed. " + e.getClickCount() + " consecutives clicks");
     }

     public void mouseReleased(MouseEvent e) {
        System.out.println("Mouse released. " + e.getClickCount() + " consecutives clicks");
     }

     public void mouseEntered(MouseEvent e) {
        System.out.println("Mouse entered");
     }

    public void mouseExited(MouseEvent e) {
        System.out.println("Mouse exited");
     }

    public void mouseClicked(MouseEvent e)
    {
        int x = e.getX();
        int y = e.getY();

        System.out.println("Mouse clicked on position: " + x + ", " + y);

        repaint();
    }
}