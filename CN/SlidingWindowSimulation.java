import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Frame {
    int seqNum;

    public Frame(int seqNum) {
        this.seqNum = seqNum;
    }
}

class Sender {
    int windowSize;
    int totalFrames;
    int base;
    int nextSeqNum;

    public Sender(int windowSize, int totalFrames) {
        this.windowSize = windowSize;
        this.totalFrames = totalFrames;
        this.base = 0;
        this.nextSeqNum = 0;
    }

    public List<Frame> sendFrames() {
        List<Frame> frames = new ArrayList<>();
        for (int i = nextSeqNum; i < Math.min(nextSeqNum + windowSize, totalFrames); i++) {
            System.out.println("Sender sending frame " + i);
            frames.add(new Frame(i));
        }
        return frames;
    }

    public void receiveAcknowledgment(boolean ack) {
        if (ack) {
            System.out.println("Sender received acknowledgment for frames " + base);
            base++;
            nextSeqNum++;
        } else {
            System.out.println("Sender timeout, retransmitting frames");
        }
    }
}

class Receiver {
    int windowSize;
    int totalFrames;
    int expectedSeqNum;

    public Receiver(int windowSize, int totalFrames) {
        this.windowSize = windowSize;
        this.totalFrames = totalFrames;
        this.expectedSeqNum = 0;
    }

    public void receiveFrames(List<Frame> frames) {
        for (Frame frame : frames) {
            if (frame.seqNum == expectedSeqNum) {
                System.out.println("Receiver received frame " + frame.seqNum);
                expectedSeqNum++;
            } else {
                System.out.println("Receiver received out-of-order frame " + frame.seqNum);
            }
        }
    }
}

public class SlidingWindowSimulation {
    public static void simulateGoBackN(int windowSize, int totalFrames) {
        Sender sender = new Sender(windowSize, totalFrames);
        Receiver receiver = new Receiver(windowSize, totalFrames);

        while (sender.base < totalFrames) {
            List<Frame> frames = sender.sendFrames();
            receiver.receiveFrames(frames);

            // Simulate acknowledgment
            boolean ack = new Random().nextBoolean();
            sender.receiveAcknowledgment(ack);
        }
    }

    public static void main(String[] args) {
        int windowSize = 3;
        int totalFrames = 8;

        System.out.println("Simulating Go-Back-N:");
        simulateGoBackN(windowSize, totalFrames);
    }
}
