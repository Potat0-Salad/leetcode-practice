class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        while(num != 0){
            if(num >= 1000){
                num -= 1000;
                result += "M";
            }
            else if(num >= 900){
                num -= 900;
                result += "CM";
            }
            else if(num >= 500){
                num -= 500;
                result += "D";
            }
            else if(num >= 400){
                num -= 400;
                result += "CD";
            }
            else if(num >= 100){
                num -= 100;
                result += "C";
            }
            else if(num >= 90){
                num -= 90;
                result += "XC";
            }
            else if(num >= 50){
                num -= 50;
                result += "L";
            }
            else if(num >= 40){
                num -= 40;
                result += "XL";
            }
            else if(num >= 10){
                num -= 10;
                result += "X";
            }
            else if(num >= 9){
                num -= 9;
                result += "IX";
            }
            else if(num >= 5){
                num -= 5;
                result += "V";
            }
            else if(num >= 4){
                num -= 4;
                result += "IV";
            }
            else{
                if(num == 3){
                    num -= 3;
                    result += "III";
                }
                else if(num == 2){
                    num -= 2;
                    result += "II";
                }
                else{
                    num -= 1;
                    result += "I";
                }
            }
        }
        return result;
    }
};