This code is designed to select Compton scattering events from Monte Carlo simulated outputs, specifically for alpha particle Ac-225.
Features:

    Events within the following energy windows suitable for Compton camera imaging will be selected:
        [210, 220] keV
        [440, 450] keV
    Users can customize the energy windows by modifying lines 189-190 in the code.

Instructions:

    Compile the code:
    ccmake CMakeLists.txt
    
    Run the program to select events within the specified energy ranges:
    ./Ac_counts

Input Requirements

    Data must be simulated using the Geant4-based simulation toolkit Gate (version 9.2 or higher required for the Compton camera module). For more information on using Gate, please visit the official website.

    An example input file, dump_1.txt, is provided in this repository. This file is a text conversion of ROOT data generated from Gate simulations.

    The dump_1.txt file contains all events detected by the Compton camera, simulating a NEMA phantom containing Ac-225 in water with a hot-to-background ratio of 30:1. For more details on the simulation settings, please refer to the following article: arXiv:2406.05220.

Output

Executing the code will generate a text output containing all validated events within the selected energy ranges. Further event selection, such as filtering out multiple-scattering or backscattering events, should be performed during the reconstruction process.
