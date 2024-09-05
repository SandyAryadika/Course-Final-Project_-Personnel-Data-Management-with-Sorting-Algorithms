#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Struct for storing data on the number of PNS based on gender and job position
    struct JumlahPNSJenisJabatan
    {
        string jabatanpns;
        int jumlahPriaPNS;
        int jumlahWanitaPNS;
        float persentotalkelaminPNS;
        float persenPriaPNS;
        float persenWanitaPNS;
        float jumlahpersenPNS;
    };

    // Struct for storing data on the number of PNS based on functional position and gender
    struct JumlahPNSJabatanFungsional
    {
        string jabatanFungsional;
        int jumlahPriaFungsi;
        int jumlahWanitaFungsi;
        float persentotalkelaminFungsi;
        float persenPriaFungsi;
        float persenWanitaFungsi;
        float jumlahpersenFungsi;
    };

int main()
{
    int pilihan;
    system("cls");
    cout << "==== Program hitung PNS UAS ====" << endl;
    cout << "1. Input jumlah PNS" << endl;
    cout << "2. Baca data PNS" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
    {
        // Sample data initialization
        const int jumlahDataJenisJabatan = 9;
        JumlahPNSJenisJabatan dataJenisJabatan[jumlahDataJenisJabatan] = {
            {"Fungsional Umum", 0, 0, 0, 0, 0},
            {"Fungsional Tertentu", 0, 0, 0, 0, 0},
            {"Struktural", 0, 0, 0, 0, 0},
            {"Eselon 1", 0, 0, 0, 0, 0},
            {"Eselon 2", 0, 0, 0, 0, 0},
            {"Eselon 3", 0, 0, 0, 0, 0},
            {"Eselon 4", 0, 0, 0, 0, 0},
            {"Eselon 5", 0, 0, 0, 0, 0},
            {"Jumlah", 0, 0, 0, 0, 0}};

        const int jumlahDataJabatanFungsional = 6;
        JumlahPNSJabatanFungsional dataJabatanFungsional[jumlahDataJabatanFungsional] = {
            {"Tenaga Pendidik", 0, 0, 0, 0, 0},
            {"Tenaga Medis", 0, 0, 0, 0, 0},
            {"Tenaga Paramedis", 0, 0, 0, 0, 0},
            {"Dosen", 0, 0, 0, 0, 0},
            {"Lainnya", 0, 0, 0, 0, 0},
            {"Jumlah", 0, 0, 0, 0, 0}};

        // Initialize totalPria and totalWanita
        float totalPriaPNS = 0;
        float totalWanitaPNS = 0;
        float totalpersenpriapns = 0;
        float totalpersenwanitapns = 0;
        int finaltotalkelaminpns = 0;

        const int jumlahData = 13;
        JumlahPNSJenisJabatan datapns[jumlahData];

        cout << endl
             << "---Tabel Jenis Jabatan PNS---" << endl;
        for (int i = 0; i < 8; ++i)
        {
            cout << endl
                 << "//// " << dataJenisJabatan[i].jabatanpns << " ////" << endl;
            cout << "Masukkan jumlah Pria dan Wanita untuk data " << dataJenisJabatan[i].jabatanpns << ":\n";
            cout << "Jumlah Pria: ";
            cin >> datapns[i].jumlahPriaPNS;
            totalPriaPNS += datapns[i].jumlahPriaPNS;

            cout << "Jumlah Wanita: ";
            cin >> datapns[i].jumlahWanitaPNS;
            totalWanitaPNS += datapns[i].jumlahWanitaPNS;

            int totalkelaminpns = totalPriaPNS + totalWanitaPNS;
            finaltotalkelaminpns += totalkelaminpns;

            // Menghitung persentase
            datapns[i].persenPriaPNS = static_cast<float>(datapns[i].jumlahPriaPNS) / (datapns[i].jumlahPriaPNS + datapns[i].jumlahWanitaPNS) * 100;
            datapns[i].persenWanitaPNS = static_cast<float>(datapns[i].jumlahWanitaPNS) / (datapns[i].jumlahPriaPNS + datapns[i].jumlahWanitaPNS) * 100;
            datapns[i].persentotalkelaminPNS = static_cast<float>(datapns[i].jumlahPriaPNS + datapns[i].jumlahWanitaPNS) / (finaltotalkelaminpns) * 100;
        }

        // Calculate the total for each position
        int totalkelaminpns[8];
        for (int i = 0; i < 8; ++i)
        {
            totalkelaminpns[i] = datapns[i].jumlahPriaPNS + datapns[i].jumlahWanitaPNS;
        }

        // Calculate the percentage for each position
        float persentotalkelaminPNS[8];
        float jumlahpersentotalkelaminpns = 0; // Inisialisasi ke nilai awal

        for (int i = 0; i < 8; ++i)
        {
            persentotalkelaminPNS[i] = static_cast<float>(totalkelaminpns[i]) / (totalPriaPNS + totalWanitaPNS) * 100;
            jumlahpersentotalkelaminpns += persentotalkelaminPNS[i];
        }

        float totalPriafungsi = 0;
        float totalWanitafungsi = 0;
        float totalpersenpriafungsi = 0;
        float totalpersenwanitafungsi = 0;
        float finaltotalkelaminfungsi = 0;

        JumlahPNSJabatanFungsional datafungsi[jumlahData];

        cout << endl
             << "---Tabel Jabatan Fungsional---" << endl;

        for (int i = 0; i < 5; ++i)
        {
            int totalkelaminfungsi = 0;
            cout << endl
                 << "//// " << dataJabatanFungsional[i].jabatanFungsional << " ////" << endl;
            cout << "Masukkan jumlah Pria dan Wanita untuk data " << dataJabatanFungsional[i].jabatanFungsional << ":\n";

            cout << "Jumlah Pria: ";
            cin >> datafungsi[i].jumlahPriaFungsi;
            totalPriafungsi += datafungsi[i].jumlahPriaFungsi;

            cout << "Jumlah Wanita: ";
            cin >> datafungsi[i].jumlahWanitaFungsi;
            totalWanitafungsi += datafungsi[i].jumlahWanitaFungsi;

            totalkelaminfungsi = totalPriafungsi + totalWanitafungsi;
            finaltotalkelaminfungsi += totalkelaminfungsi;

            // Menghitung persentase
            datafungsi[i].persenPriaFungsi = static_cast<float>(datafungsi[i].jumlahPriaFungsi) / (datafungsi[i].jumlahPriaFungsi + datafungsi[i].jumlahWanitaFungsi) * 100;
            datafungsi[i].persentotalkelaminFungsi = static_cast<float>(datafungsi[i].jumlahPriaFungsi + datafungsi[i].jumlahWanitaFungsi) / finaltotalkelaminfungsi * 100;

            // Corrected parentheses in the following line
            datafungsi[i].persenWanitaFungsi = static_cast<float>(datafungsi[i].jumlahWanitaFungsi) / (datafungsi[i].jumlahPriaFungsi + datafungsi[i].jumlahWanitaFungsi) * 100;
        }

        // Calculate the total for each position
        int totalkelaminfungsi[5];
        for (int i = 0; i < 5; ++i)
        {
            totalkelaminfungsi[i] = datafungsi[i].jumlahPriaFungsi + datafungsi[i].jumlahWanitaFungsi;
        }

        // Calculate the percentage for each position
        float persentotalkelaminfungsi[5];
        float jumlahpersentotalkelaminfungsi = 0;
        for (int i = 0; i < 5; ++i)
        {
            persentotalkelaminfungsi[i] = static_cast<float>(totalkelaminfungsi[i]) / (totalPriafungsi + totalWanitafungsi) * 100;
            jumlahpersentotalkelaminfungsi += persentotalkelaminfungsi[i];
        }

        // Menggunakan variabel total untuk menghitung jumlah jabatan PNS dan fungsional secara keseluruhan
        int totalPNS = totalPriaPNS + totalWanitaPNS;
        int totalfungsi = totalPriafungsi + totalWanitafungsi;

        cout << "Total Jenis Jabatan PNS (Pria + Wanita): " << totalPNS << endl;
        cout << "Total Jabatan Fungsional (Pria + Wanita): " << totalfungsi << endl;

        // Menampilkan hasil persentase untuk setiap jabatan (Tabel Jenis Jabatan)
        for (int i = 0; i < 8; ++i)
        {
            cout << "//// " << dataJenisJabatan[i].jabatanpns << " ////" << endl;
            cout << "Persentase Pria: " << datapns[i].persenPriaPNS << "%" << endl;
            cout << "Persentase Wanita: " << datapns[i].persenWanitaPNS << "%" << endl
                 << endl;
            // totalpersenpriapns += datapns[i].persenPriaPNS;
            // totalpersenwanitapns += datapns[i].persenWanitaPNS;
            cout << "Total Persen Jumlah banyak PNS untuk jenis jabatan " << dataJenisJabatan[i].jabatanpns << " = " << persentotalkelaminPNS[i] << "%" << endl;
        }

        totalpersenpriapns = (totalPriaPNS / totalPNS) * 100;
        totalpersenwanitapns = (totalWanitaPNS / totalPNS) * 100;
        float finaltotalpersenpns = totalpersenpriapns + totalpersenwanitapns;
        cout << "Total Seluruh Persen PNS jenis jabatan :" << finaltotalpersenpns << endl;

        // Menampilkan hasil persentase untuk setiap jabatan (Tabel Jabatan Fungsional)
        for (int i = 0; i < 5; ++i)
        {
            cout << "//// " << dataJabatanFungsional[i].jabatanFungsional << " ////" << endl;
            cout << "Persentase Pria: " << datafungsi[i].persenPriaFungsi << "%" << endl;
            cout << "Persentase Wanita: " << datafungsi[i].persenWanitaFungsi << "%" << endl
                 << endl;
            // totalpersenpriafungsi += datafungsi[i].persenPriaFungsi;
            // totalpersenwanitafungsi += datafungsi[i].persenWanitaFungsi;
            cout << "Total Persen Jumlah banyak PNS untuk jabatan fungsional " << dataJabatanFungsional[i].jabatanFungsional << " = " << persentotalkelaminfungsi[i] << "%" << endl;
        }

        totalpersenpriafungsi = (totalPriafungsi / totalfungsi) * 100;
        totalpersenwanitafungsi = (totalWanitafungsi / totalfungsi) * 100;
        float finaltotalpersenfungsi = totalpersenpriafungsi + totalpersenwanitafungsi;
        cout << "Total Seluruh Persen PNS jabatan fungsional :" << finaltotalpersenfungsi << endl;

        // Save data to console (Jenis Jabatan)
        cout << endl
             << "=== Persentase Jenis Jabatan ===" << endl;
        cout << left << setw(20) << "Jenis Jabatan" << setw(10) << "Pria" << setw(10) << "Wanita" << setw(15) << "Persen Pria" << setw(15) << "Persen Wanita" << setw(20) << "Jumlah" << setw(15) << "Persen Jumlah" << endl;
        for (int i = 0; i < 8; ++i)
        {
            cout << left << setw(20) << dataJenisJabatan[i].jabatanpns << setw(10) << datapns[i].jumlahPriaPNS << setw(10) << datapns[i].jumlahWanitaPNS
                 << setw(15) << fixed << setprecision(2) << datapns[i].persenPriaPNS << "%" << setw(15) << datapns[i].persenWanitaPNS << "%" << setw(20) << fixed << setprecision(2) << (datapns[i].jumlahPriaPNS + datapns[i].jumlahWanitaPNS) << setw(20) << persentotalkelaminPNS[i] << "%" << endl;
        }
        cout << left << setw(20) << dataJenisJabatan[8].jabatanpns << setw(10) << fixed << setprecision(0) << totalPriaPNS << setw(10) << fixed << setprecision(0) << totalWanitaPNS
             << setw(15) << fixed << setprecision(2) << totalpersenpriapns << "%" << setw(15) << totalpersenwanitapns << "%" << setw(20) << fixed << setprecision(2) << totalPNS << setw(20) << jumlahpersentotalkelaminpns << "%" << endl;

        // Save data to console (fungsional)
        cout << endl
             << "=== Persentase Jabatan Fungsional ===" << endl;
        cout << left << setw(20) << "Jabatan Fungsional" << setw(10) << "Pria" << setw(10) << "Wanita" << setw(15) << "Persen Pria" << setw(15) << "Persen Wanita" << setw(20) << "Jumlah" << setw(15) << "Persen Jumlah" << endl;
        for (int i = 0; i < 5; ++i)
        {
            cout << left << setw(20) << dataJabatanFungsional[i].jabatanFungsional << setw(10) << datafungsi[i].jumlahPriaFungsi << setw(10) << datafungsi[i].jumlahWanitaFungsi
                 << setw(15) << fixed << setprecision(2) << datafungsi[i].persenPriaFungsi << "%" << setw(15) << datafungsi[i].persenWanitaFungsi << "%" << setw(20) << fixed << setprecision(2) << (datafungsi[i].jumlahPriaFungsi + datafungsi[i].jumlahWanitaFungsi) << setw(20) << persentotalkelaminfungsi[i] << "%" << endl;
        }
        cout << left << setw(20) << dataJabatanFungsional[5].jabatanFungsional << setw(10) << fixed << setprecision(0) << totalPriafungsi << setw(10) << fixed << setprecision(0) << totalWanitafungsi
             << setw(15) << fixed << setprecision(2) << totalpersenpriafungsi << "%" << setw(15) << totalpersenwanitafungsi << "%" << setw(20) << fixed << setprecision(2) << totalfungsi << setw(20) << jumlahpersentotalkelaminfungsi << "%" << endl;

        // Exponential Search
        int maxPNS = 0;
        string jabatanMaxPNS;

        int i = 1;
        while (i < 8)
        {
            if (totalkelaminpns[i] > maxPNS)
            {
                maxPNS = totalkelaminpns[i];
                jabatanMaxPNS = dataJenisJabatan[i].jabatanpns;
            }
            i *= 2;
        }

        int left = i / 2;
        int right = min(i, 8);

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (totalkelaminpns[mid] > maxPNS)
            {
                maxPNS = totalkelaminpns[mid];
                jabatanMaxPNS = dataJenisJabatan[mid].jabatanpns;
            }

            if (totalkelaminpns[mid] == maxPNS)
            {
                break; // Jika ada duplikasi, keluar dari loop
            }
            else if (totalkelaminpns[mid] < maxPNS)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        cout << "\nJenis jabatan dengan PNS terbanyak: " << jabatanMaxPNS << " (" << maxPNS << " PNS)" << endl;

        // Bubble sort jabatan fungsional berdasarkan total PNS secara descending
        for (int i = 0; i < 5 - 1; ++i)
        {
            for (int j = 0; j < 5 - i - 1; ++j)
            {
                int totalPNS1 = datafungsi[j].jumlahPriaFungsi + datafungsi[j].jumlahWanitaFungsi;
                int totalPNS2 = datafungsi[j + 1].jumlahPriaFungsi + datafungsi[j + 1].jumlahWanitaFungsi;

                if (totalPNS1 < totalPNS2)
                {
                    // Tukar datafungsi[j] dan datafungsi[j + 1]
                    swap(datafungsi[j], datafungsi[j + 1]);
                    // Tukar juga dataJabatanFungsional[j] dan dataJabatanFungsional[j + 1]
                    swap(dataJabatanFungsional[j], dataJabatanFungsional[j + 1]);
                }
            }
        }

        // Tampilkan posisi fungsional secara descending
        cout << "\n---Urutan Jabatan Fungsional dari Terbanyak---" << endl;
        for (int i = 0; i < 5; ++i)
        {
            cout << dataJabatanFungsional[i].jabatanFungsional << " - " << (datafungsi[i].jumlahPriaFungsi + datafungsi[i].jumlahWanitaFungsi) << " PNS" << endl;
        }

        // Buka file untuk penulisan
        ofstream outputFile("output.txt");

        // Periksa apakah file berhasil dibuka
        if (!outputFile.is_open())
        {
            cerr << "Error membuka file!" << endl;
            return 1;
        }
        else
        {
            // Save data to file (Jenis Jabatan)
            outputFile << endl
                       << "=== Persentase Jenis Jabatan ===" << endl;
            outputFile << left << setw(20) << "Jenis Jabatan" << setw(10) << "Pria" << setw(10) << "Wanita" << setw(15) << "Persen Pria" << setw(15) << "Persen Wanita" << setw(20) << "Jumlah" << setw(15) << "Persen Jumlah" << endl;
            for (int i = 0; i < 8; ++i)
            {
                outputFile << left << setw(20) << dataJenisJabatan[i].jabatanpns << setw(10) << datapns[i].jumlahPriaPNS << setw(10) << datapns[i].jumlahWanitaPNS
                           << setw(15) << fixed << setprecision(2) << datapns[i].persenPriaPNS << "%" << setw(15) << datapns[i].persenWanitaPNS << "%" << setw(20) << fixed << setprecision(2) << (datapns[i].jumlahPriaPNS + datapns[i].jumlahWanitaPNS) << setw(20) << persentotalkelaminPNS[i] << "%" << endl;
            }
            outputFile << left << setw(20) << dataJenisJabatan[8].jabatanpns << setw(10) << fixed << setprecision(0) << totalPriaPNS << setw(10) << fixed << setprecision(0) << totalWanitaPNS
                       << setw(15) << fixed << setprecision(2) << totalpersenpriapns << "%" << setw(15) << totalpersenwanitapns << "%" << setw(20) << fixed << setprecision(2) << totalPNS << setw(20) << jumlahpersentotalkelaminpns << "%" << endl;

            // Save data to file (fungsional)
            outputFile << endl
                       << "=== Persentase Jabatan Fungsional ===" << endl;
            outputFile << left << setw(20) << "Jabatan Fungsional" << setw(10) << "Pria" << setw(10) << "Wanita" << setw(15) << "Persen Pria" << setw(15) << "Persen Wanita" << setw(20) << "Jumlah" << setw(15) << "Persen Jumlah" << endl;
            for (int i = 0; i < 5; ++i)
            {
                outputFile << left << setw(20) << dataJabatanFungsional[i].jabatanFungsional << setw(10) << datafungsi[i].jumlahPriaFungsi << setw(10) << datafungsi[i].jumlahWanitaFungsi
                           << setw(15) << fixed << setprecision(2) << datafungsi[i].persenPriaFungsi << "%" << setw(15) << datafungsi[i].persenWanitaFungsi << "%" << setw(20) << fixed << setprecision(2) << (datafungsi[i].jumlahPriaFungsi + datafungsi[i].jumlahWanitaFungsi) << setw(20) << persentotalkelaminfungsi[i] << "%" << endl;
            }
            outputFile << left << setw(20) << dataJabatanFungsional[5].jabatanFungsional << setw(10) << fixed << setprecision(0) << totalPriafungsi << setw(10) << fixed << setprecision(0) << totalWanitafungsi
                       << setw(15) << fixed << setprecision(2) << totalpersenpriafungsi << "%" << setw(15) << totalpersenwanitafungsi << "%" << setw(20) << fixed << setprecision(2) << totalfungsi << setw(20) << jumlahpersentotalkelaminfungsi << "%" << endl;

            // Jabatan terbanyak
            outputFile << "\nJenis jabatan dengan PNS terbanyak: " << jabatanMaxPNS << " (" << maxPNS << " PNS)" << endl;

            // Display functional positions in descending order
            outputFile << "\n---Urutan Jabatan Fungsional dari Terbanyak---" << endl;
            for (int i = 0; i < 5; ++i)
            {
                outputFile << dataJabatanFungsional[i].jabatanFungsional << " - " << (datafungsi[i].jumlahPriaFungsi + datafungsi[i].jumlahWanitaFungsi) << " PNS" << endl;
            }
            // Tutup file
            outputFile.close();
        }
    }
    break;

    case 2:

        ifstream fileIn("output.txt");

        if (!fileIn.is_open())
        {
            cout << "File tidak dapat dibuka" << endl;
            return 0;
        }

        string line;
        while (getline(fileIn, line))
        {
            cout << line << endl;
        }

        fileIn.close();
        break;
    }

    return 0;
}
