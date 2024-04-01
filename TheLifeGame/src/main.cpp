




///из удалённого LifeReader. Возможно, потом использую
/*std::string firstString;
    double n;
    life >> firstString >> n;
    //std::cout << firstString << " " << n << std::endl;
    if (firstString != "#Life" || n != 1.06){
        throw std::invalid_argument("Not lifeUniverse file\n");
    }
    std::string otherStrings;
    for (int i {}; i < 2; ++i){
        life >> otherStrings;
        if (otherStrings == "#N"){
            life.get();
            getline(life, this->universeName, '\n');
            //std::cout << this->universeName << std::endl;
            otherStrings.clear();
        }else if (otherStrings == "#R"){
            otherStrings.clear();
            life >> otherStrings;
            //std::cout << otherStrings << std::endl;
            int ruleSize = (int)otherStrings.size();
            bool slash = false;
            for (int j {}; j < ruleSize; ++j){
                if (otherStrings[j] == '/'){
                    slash = true;
                }
                if (isdigit(otherStrings[j])){
                    if (!slash){
                        neighboursToBirth.push_back(otherStrings[j] - '0'); //чтоб вот таких уровней вложенности не было
                    }else{
                        neighboursToSurvive.push_back(otherStrings[j] - '0'); //потом вынесу в отдельную функцию
                    }

                }
            }
        }else{
            ///вернуться на один символ назад
            ///и после выхода из for начать читать координаты живых клеток
            ///это произойдёт, если имя или правило пропущено



            break;
        }
    }*/


int main(){




    return 0;
}
