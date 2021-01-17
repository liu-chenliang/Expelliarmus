#include <iostream>
using namespace std;

int blood[6] = {100, 100, 100, 100, 100, 100};
int crystal[6]= {100, 100, 100, 100, 100, 100};
bool half[6] = {false, false, false, false, false, false};
double usehalf(int x)
{
    if(half[x] == true)
    {
        half[x] = false;
        return 0.5;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int n;
    int w = 1;
    cout << "本游戏支持5人对战" << endl;
    cout << "1是水技能，消耗4个水晶，同时使敌人的血量减少4点" << endl;
    cout << "2是火技能，消耗10个水晶，同时使敌人的血量减少11点"	 << endl;
    cout << "3是风技能，消耗10个水晶，同时使敌人的血量减少5点，并把下一次发动技能的水晶数除以2" << endl;
    cout << "4是土技能，消耗18个水晶，同时使敌人的血量除以2（如是奇数就加1再除以2）" << endl;
    while (blood[1] > 0 && blood[2] > 0 && blood[3] > 0 && blood[4] > 0 && blood[5] && crystal[1] > 0 && crystal[2] > 0)
    {
        if(w == 5)
        {
            w = 1;
        }
        cout << w << "玩家出牌！" << endl;
        cin >> n;
        if (n == 1) {
            blood[w + 1] -= 4;
            crystal[w] -= 4 * usehalf(w);
        }
        else
        {
            if (n == 2)
            {
                blood[w + 1] -= 11;
                crystal[w] -= 10 * usehalf(w);
            }
            else
            {
                if (n == 3)
                {
                    blood[w + 1] -= 5;
                    crystal[w] -= 10 * usehalf(w);
                    half[1] = true;
                }
                else
                {
                    if(blood[w + 1] % 2 == 0)
                    {
                        blood[w + 1] /= 2;
                    }
                    else
                    {
                        blood[w + 1] = (blood[w + 1] + 1) / 2;
                    }
                    crystal[w] -= 18 * usehalf(w);
                    
                }
            }
        }
        w++;
    }
    return 0;
}
