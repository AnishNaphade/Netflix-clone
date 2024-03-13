package com.main.crc.crc;
import java.util.Scanner;

public class CN_Assn3 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input dividend and divisor
        System.out.print("Enter the 7/8 bits ASCII code (dividend): ");
        String dividend = scanner.nextLine();
        System.out.print("Enter the divisor: ");
        String divisor = scanner.nextLine();

        // Perform CRC encoding
        String encodedData = encodeData(dividend, divisor);
        System.out.println("Encoded Data (with CRC): " + encodedData);

        // Simulate transmission by introducing errors
        System.out.print("Enter the received data: ");
        String receivedData = scanner.nextLine();

        // Perform CRC decoding
        boolean isErrorDetected = decodeData(receivedData, divisor);

        if (isErrorDetected) {
            System.out.println("Error detected in received data.");
        } else {
            System.out.println("No errors detected in received data.");
        }

        scanner.close();
    }

    // CRC Encoding
    private static String encodeData(String data, String divisor) {
        int dataLength = data.length();
        int divisorLength = divisor.length();
        StringBuilder encodedData = new StringBuilder(data);

        // Append zeros to the dividend (data) for padding
        for (int i = 0; i < divisorLength - 1; i++) {
            encodedData.append('0');
        }

        for (int i = 0; i < dataLength; i++) {
            if (encodedData.charAt(i) == '1') {
                // XOR operation
                for (int j = 0; j < divisorLength; j++) {
                    encodedData.setCharAt(i + j, xor(encodedData.charAt(i + j), divisor.charAt(j)));
                }
            }
        }

        return encodedData.toString();
    }

    // CRC Decoding
    private static boolean decodeData(String receivedData, String divisor) {
        int dataLength = receivedData.length();
        int divisorLength = divisor.length();
        StringBuilder receivedDataBuilder = new StringBuilder(receivedData);

        for (int i = 0; i <= dataLength - divisorLength; i++) {
            if (receivedDataBuilder.charAt(i) == '1') {
                // XOR operation
                for (int j = 0; j < divisorLength; j++) {
                    receivedDataBuilder.setCharAt(i + j, xor(receivedDataBuilder.charAt(i + j), divisor.charAt(j)));
                }
            }
        }

        // Check for remaining errors
        for (int i = dataLength - divisorLength + 1; i < dataLength; i++) {
            if (receivedDataBuilder.charAt(i) == '1') {
                return true; // Error detected
            }
        }

        return false; // No errors detected
    }

    // XOR operation
    private static char xor(char a, char b) {
        return (a == b) ? '0' : '1';
    }
}
