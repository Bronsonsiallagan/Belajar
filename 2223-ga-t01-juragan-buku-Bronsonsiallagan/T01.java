// 12S22025 Bronson TM Siallagan
// 12S22049 Agnes Monica Sanjani Harefa
import java.util.*;
import java.lang.Math;

public class T01 {
    private static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        String iSBN;
        String judul;
        String penulis;
        String tahunterbit;
        String penerbit;
        String formatbuku;
        double hargapembelian;
        double minimum;
        int jumlahstok;
        double rating;
        
        iSBN = input.nextLine();
        judul = input.nextLine();
        penulis = input.nextLine();
        tahunterbit = input.nextLine();
        penerbit = input.nextLine();
        formatbuku = input.nextLine();
        hargapembelian = input.nextDouble();
        minimum = input.nextDouble();
        jumlahstok = input.nextInt();
        rating = input.nextDouble();
        System.out.println(iSBN + "|" + judul + "|" + penulis + "|" + tahunterbit + "|" + penerbit + "|" + formatbuku + "|" + hargapembelian + "|" + minimum + "|" + jumlahstok + "|" + rating);
    }
}
