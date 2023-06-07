// 12S22025 - Bronson TM Siallagan
// 12S22049 - Agnes Monica Sanjani Harefa 


  import java.util.*;
import java.lang.Math;

public class T03 {
    private static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        String iSBN;
        
        do {
            String judul;
            String penulis;
            String tahunterbit;
            String penerbit;
            String formatbuku;
            String diskon;
            double harga;
            double minimum;
            double totaldiskon;
            String keterangan;
            int stok;
            int persen;
            double rating;
            String kategori;
            
            kategori = "";
            String tUB;
            
            persen = 100;
            iSBN = input.nextLine();
            if (iSBN.equals("---")) {
            } else {
                judul = input.nextLine();
                penulis = input.nextLine();
                tahunterbit = input.nextLine();
                penerbit = input.nextLine();
                formatbuku = input.nextLine();
                harga = Double.parseDouble(input.nextLine());
                minimum = Double.parseDouble(input.nextLine());
                if (minimum > 0) {
                    diskon = "---";
                } else {
                    if (minimum < -(harga * 40 / 100)) {
                        diskon = "Once in a lifetime";
                    } else {
                        if (minimum < -(harga * 20 / 100)) {
                            diskon = "Never come twice";
                        } else {
                            diskon = "No regret";
                        }
                    }
                }
                stok = Integer.parseInt(input.nextLine());
                rating = Double.parseDouble(input.nextLine());
                if (rating >= 4.7) {
                    kategori = "Best Pick";
                } else {
                    if (rating >= 4.5) {
                        kategori = "Must Read";
                    } else {
                        if (rating >= 4.0) {
                            kategori = "Recommended";
                        } else {
                            if (rating >= 3.0) {
                                kategori = "Average";
                            } else {
                                if (rating <= 3.0) {
                                    kategori = "Low";
                                }
                            }
                        }
                    }
                }
                if (diskon.equals("Once in a lifetime") && kategori.equals("Best Pick")) {
                    tUB = "The ultimate best";
                } else {
                    tUB = "---";
                }
                System.out.println(iSBN + "|" + judul + "|" + penulis + "|" + tahunterbit + "|" + penerbit + "|" + formatbuku + "|" + harga + "|" + minimum + "|" + stok + "|" + rating + "|" + kategori + "|" + diskon + "|" + tUB);
            }
        } while (!iSBN.equals("---"));
    }
}
