
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


// Structure to hold data for each row
struct RowData {
    string P;
    double Processing;
    string d;
    double ump_1cxx;
    string VarName5;
    double VarName6;
    string VarName7;
    double VarName8;
    string VarName9;
    double VarName10;
    string VarName11;
    double VarName12;
    string VarName13;
    double VarName14;
    string VarName15;
    double VarName16;
    string VarName17;
    double VarName18;
    string VarName19;
    double VarName20;
    string VarName21;
    double VarName22;
    string VarName23;
    double VarName24;
    string VarName25;
    double VarName26;
    string VarName27;
    double VarName28;
    string VarName29;
    double VarName30;
    string VarName31;
    double VarName32;
    string VarName33;
    double VarName34;
    string VarName35;
    double VarName36;
    string VarName37;
    double VarName38;
    string VarName39;
    double VarName40;
    string VarName41;
    double VarName42;
    string VarName43;
    double VarName44;
    string VarName45;
    double VarName46;
    string VarName47;
    double VarName48;
    string VarName49;
    double VarName50;
    string VarName51;
    double VarName52;
    string VarName53;
    double VarName54;
    string VarName55;
    double VarName56;
    string VarName57;
    string VarName58;
    string VarName59;
    string VarName60;
    double VarName61;
    string VarName62;
};

vector<RowData> readFile(const string& filename, int startRow) {
    ifstream file(filename);
    vector<RowData> data;
    string line;

    // Skip initial rows
    for (int i = 0; i < startRow - 1; ++i) {
        getline(file, line);
    }

    while (getline(file, line)) {
        istringstream ss(line);
        RowData row;
        ss >> row.P >> row.Processing >> row.d >> row.ump_1cxx >> row.VarName5 >> row.VarName6
           >> row.VarName7 >> row.VarName8 >> row.VarName9 >> row.VarName10 >> row.VarName11
           >> row.VarName12 >> row.VarName13 >> row.VarName14 >> row.VarName15 >> row.VarName16
           >> row.VarName17 >> row.VarName18 >> row.VarName19 >> row.VarName20 >> row.VarName21
           >> row.VarName22 >> row.VarName23 >> row.VarName24 >> row.VarName25 >> row.VarName26
           >> row.VarName27 >> row.VarName28 >> row.VarName29 >> row.VarName30 >> row.VarName31
           >> row.VarName32 >> row.VarName33 >> row.VarName34 >> row.VarName35 >> row.VarName36
           >> row.VarName37 >> row.VarName38 >> row.VarName39 >> row.VarName40 >> row.VarName41
           >> row.VarName42 >> row.VarName43 >> row.VarName44 >> row.VarName45 >> row.VarName46
           >> row.VarName47 >> row.VarName48 >> row.VarName49 >> row.VarName50 >> row.VarName51
           >> row.VarName52 >> row.VarName53 >> row.VarName54 >> row.VarName55 >> row.VarName56
           >> row.VarName57 >> row.VarName58 >> row.VarName59 >> row.VarName60 >> row.VarName61
           >> row.VarName62;
        data.push_back(row);
    }

    file.close();
    return data;
}

int main() {
   
   // string filename = "dump_2.txt";
int ii = 1;
   std::string filename = "dump_CC_" + std::to_string(ii) + ".txt";
    int startRow = 5;

    vector<RowData> data = readFile(filename, startRow);

    // Extract indices every 10th line
    vector<int> indices;
    for (int i = 1; i < data.size(); i += 10) {
        indices.push_back(i);
    }

    // Extract the required data
    vector<double> eventID, trackID, parentID, time, PosX, PosY, PosZ, sourcePosX, sourcePosY, sourcePosZ, EnerIni, EnerFin;
    vector<string> postStep, processname, layername;

    for (int idx : indices) {
        eventID.push_back(data[idx].VarName8);
        trackID.push_back(data[idx].VarName12);
        parentID.push_back(data[idx].VarName14);
        time.push_back(data[idx].VarName18);
        PosX.push_back(data[idx].VarName26);
        PosY.push_back(data[idx].VarName28);
        PosZ.push_back(data[idx].VarName30);
        sourcePosX.push_back(data[idx].VarName38);
        sourcePosY.push_back(data[idx].VarName40);
        sourcePosZ.push_back(data[idx].VarName42);
        EnerIni.push_back(data[idx].VarName56);
        EnerFin.push_back(data[idx].VarName54);
        postStep.push_back(data[idx].VarName58);
        processname.push_back(data[idx].VarName59);
        layername.push_back(data[idx].VarName60);
    }

    // Further processing (similar to MATLAB code)
    vector<int> nb_interaction(indices.size(), 0);
    vector<int> row_id(indices.size(), 0);
    cout << "Hits number: " <<indices.size() << endl;

    int i = 0;
    for (int RefEveID = 0; RefEveID < EnerFin.size(); ++RefEveID) {
        for (int NonRefEveID = RefEveID + 1; NonRefEveID < EnerFin.size(); ++NonRefEveID) {
            if (trackID[RefEveID] != trackID[NonRefEveID]) {
                i = i+1;
            	//continue;
            } else {
            	nb_interaction[i] = nb_interaction[i]+1;
            	row_id[i] = RefEveID;
                //nb_interaction[RefEveID]++;
              //  row_id[RefEveID][nb_interaction[RefEveID] - 1] = RefEveID;
                //break;

            }
            break;
        }
    }
    cout << "Number of diff event id: " <<i << endl;
    vector<vector<double>> V1, V2, Energy_V1, Energy_V2, source_V1, source_V2;
    vector<double> sq;
  //  int counts_2inter=0;
    for (int j = 0; j < nb_interaction.size(); ++j) {
     // cout << "Number of interactions: " << nb_interaction[j] << endl; 
 if (nb_interaction[j] == 1) {
            V1.push_back({PosX[row_id[j]], PosY[row_id[j]], PosZ[row_id[j]]});
            V2.push_back({PosX[row_id[j] + 1], PosY[row_id[j] + 1], PosZ[row_id[j] + 1]});
            Energy_V1.push_back({EnerFin[row_id[j]], EnerIni[row_id[j]]});
            Energy_V2.push_back({EnerFin[row_id[j] + 1], EnerIni[row_id[j] + 1]});
            source_V1.push_back({sourcePosX[row_id[j]], sourcePosY[row_id[j]], sourcePosZ[row_id[j]]});
            source_V2.push_back({sourcePosX[row_id[j] + 1], sourcePosY[row_id[j] + 1], sourcePosZ[row_id[j]+ 1]});
            sq.push_back(nb_interaction[j]);
}
    }

    int n1 = count_if(EnerIni.begin(), EnerIni.end(), [](double e) { return e > 0.21 && e < 0.22; });
    int n2 = count_if(EnerIni.begin(), EnerIni.end(), [](double e) { return e > 0.44 && e < 0.45; });

    cout << "Number of 2 interactions: " <<V1.size() << endl;
    cout << "Number of EnerIni between 0.21 and 0.22: " << n1 << endl;
    cout << "Number of EnerIni between 0.44 and 0.45: " << n2 << endl;





    std::string filename1 = "CC_coincidence_NEMA_water_ratio30_1.txt";
    
    std::ofstream file;
    file.open(filename1);

    file << std::fixed << std::setprecision(6); // Set precision for floating-point output


    for (size_t j = 0; j < V1.size(); ++j) {
        file << "SE\n";
        file << "ET CO\n";
        file << "ID " << j + 1 << "\n";
        file << "TI 0.0\n";
        file << "SQ " << sq[j] + 1 << "\n";
        file << "CT 0 0\n";
        file << "TL 1\n";
        file << "TE 0\n";
       // file << "CE " << (Energy_V1[j][1] - Energy_V1[j][0]) * 1000 << " 0   " << (Energy_V1[j][0] - Energy_V2[j][0]) * 1000 << " 0\n"; // unit keV
         file << "CE " << (Energy_V1[j][0]) * 1000 << " 0   " << (Energy_V1[j][1] - Energy_V1[j][0]) * 1000 << " 0\n";
        file << "CD " << V1[j][0] / 10 << " " << V1[j][1] / 10 << " " << V1[j][2] / 10 << "   0 0 0   " << V2[j][0] / 10 << " " << V2[j][1] / 10 << " " << V2[j][2] / 10 << "   0 0 0   0 0 0   0 0 0\n"; // unit cm
        file << "LA 0.0\n";
    }

    file.close();



    return 0;
}

