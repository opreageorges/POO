void clearscreen(){
    for (int i=0; i<1000; i++){
        std::cout << "\n";
    }
}

void endgame(int x){
    switch (x) {
        case 1:
            std::cout << "AI PIERDUT ;(\n";
            break;
        case 2:
            std::cout << "AI CASTIGAT\n";
            break;

    }
}