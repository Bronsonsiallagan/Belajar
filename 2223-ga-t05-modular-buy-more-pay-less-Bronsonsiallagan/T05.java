// 12S22025 - Bronson TM Siallagan
// 12S22048 - Ira Silalahi 


import java.util.*;
import java.lang.Math;

public class T05 {
    private static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        double[] totalHarga = new double[3];
        double totalHargaAkhir;
        
        totalHargaAkhir = 0;
        proses(totalHarga, totalHargaAkhir);
        output(totalHarga, totalHargaAkhir);
    }
    
    public static void output(double[] totalHarga, double totalHargaAkhir) {
        totalHargaAkhir = totalHarga[0] + totalHarga[1] + totalHarga[2];
        System.out.println(toFixed(totalHargaAkhir,2));
    }
    
    public static void proses(double[] totalHarga, double totalhargaakhir) {
        String[] iSBN = new String[3];
        int[] jumlahBuku = new int[3];
        double[] harga = new double[3];
        
        jumlahBuku[0] = 0;
        jumlahBuku[1] = 0;
        jumlahBuku[2] = 0;
        harga[0] = 0;
        harga[1] = 0;
        harga[2] = 0;
        totalHarga[0] = 0;
        totalHarga[1] = 0;
        totalHarga[2] = 0;
        int n, jumlahBuku0, jumlahBuku1, jumlahBuku2;
        
        n = 0;
        jumlahBuku0 = 0;
        jumlahBuku1 = 0;
        jumlahBuku2 = 0;
        String buku0, buku1, buku2;
        
        buku0 = "Buku";
        buku1 = "Buku";
        buku2 = "Buku";
        int nol, satu, dua;
        
        nol = 0;
        satu = 1;
        dua = 2;
        do {
            iSBN[n] = input.nextLine();
            if (iSBN[n].equals("---")) {
                n = 3;
            } else {
                if (iSBN[n].equals(iSBN[0])) {
                    if (nol == 0) {
                        buku0 = iSBN[n];
                    }
                    if (iSBN[0].equals(buku0)) {
                        n = 0;
                        harga[n] = Double.parseDouble(input.nextLine());
                        jumlahBuku[n] = Integer.parseInt(input.nextLine());
                        jumlahBuku0 = jumlahBuku0 + jumlahBuku[n];
                        nol = 3;
                        n = n + 1;
                    } else {
                        if (satu == 1) {
                            buku1 = iSBN[n];
                        }
                        if (iSBN[0].equals(buku1)) {
                            n = 1;
                            harga[n] = Double.parseDouble(input.nextLine());
                            jumlahBuku[n] = Integer.parseInt(input.nextLine());
                            jumlahBuku1 = jumlahBuku1 + jumlahBuku[n];
                            nol = 3;
                            n = n + 1;
                        } else {
                            n = 2;
                            harga[n] = Double.parseDouble(input.nextLine());
                            jumlahBuku[n] = Integer.parseInt(input.nextLine());
                            jumlahBuku2 = jumlahBuku2 + jumlahBuku[n];
                            nol = 3;
                            n = 0;
                        }
                    }
                } else {
                    if (iSBN[n].equals(iSBN[1])) {
                        if (satu == 1) {
                            buku1 = iSBN[n];
                        }
                        if (iSBN[1].equals(buku1)) {
                            n = 1;
                            harga[n] = Double.parseDouble(input.nextLine());
                            jumlahBuku[n] = Integer.parseInt(input.nextLine());
                            jumlahBuku1 = jumlahBuku1 + jumlahBuku[n];
                            satu = 3;
                            n = n + 1;
                        } else {
                            n = 2;
                            harga[n] = Double.parseDouble(input.nextLine());
                            jumlahBuku[n] = Integer.parseInt(input.nextLine());
                            jumlahBuku2 = jumlahBuku2 + jumlahBuku[n];
                            satu = 3;
                            n = 0;
                        }
                    } else {
                        if (iSBN[n].equals(iSBN[2])) {
                            if (dua == 2) {
                                buku2 = iSBN[n];
                            }
                            if (iSBN[2].equals(buku2)) {
                                n = 2;
                                harga[n] = Double.parseDouble(input.nextLine());
                                jumlahBuku[n] = Integer.parseInt(input.nextLine());
                                jumlahBuku2 = jumlahBuku2 + jumlahBuku[n];
                                dua = 3;
                                n = 0;
                            }
                        }
                    }
                }
            }
        } while (n < 3);
        if (jumlahBuku0 >= 20) {
            harga[0] = harga[0] - harga[0] * 0.12;
        } else {
            if (jumlahBuku0 >= 10) {
                harga[0] = harga[0] - harga[0] * 0.05;
            } else {
                if (jumlahBuku0 >= 5) {
                    harga[0] = harga[0] - harga[0] * 0.02;
                }
            }
        }
        totalHarga[0] = harga[0] * jumlahBuku0;
        if (jumlahBuku1 >= 20) {
            harga[1] = harga[1] - harga[1] * 0.12;
        } else {
            if (jumlahBuku1 >= 10) {
                harga[1] = harga[1] - harga[1] * 0.05;
            } else {
                if (jumlahBuku1 >= 5) {
                    harga[1] = harga[1] - harga[1] * 0.02;
                }
            }
        }
        totalHarga[1] = harga[1] * jumlahBuku1;
        if (jumlahBuku2 >= 20) {
            harga[2] = harga[2] - harga[2] * 0.12;
        } else {
            if (jumlahBuku2 >= 10) {
                harga[2] = harga[2] - harga[2] * 0.05;
            } else {
                if (jumlahBuku2 >= 5) {
                    harga[2] = harga[2] - harga[2] * 0.02;
                }
            }
        }
        totalHarga[2] = harga[2] * jumlahBuku2;
    }
    
    private static String toFixed(double value, int digits) {
        return String.format("%." + digits + "f", value);
    }
}
