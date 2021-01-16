#include <iostream>
using namespace std;

bool half1;
bool half2;
double usehalf(int x)
{
    if(x == 1 && half1 == true)
    {
        half1 = false;
        return 0.5;
    }
    else
    {
        if(x == 2 && half2 == true)
        {
            half2 = false;
            return 0.5;
        }
        return 1;
    }
}
int main()
{
    int crystal1 = 100;
    int crystal2 = 100;
    int n;
    int blood1 = 100;
    int blood2 = 100;
    cout << "1是水技能，消耗4个水晶，同时使敌人的血量减少4点" << endl;
    cout << "2是火技能，消耗10个水晶，同时使敌人的血量减少11点" << endl;
    cout << "3是风技能，消耗10个水晶，同时使敌人的血量减少5点，并把下一次发动技能的水晶数除以2" << endl;
    cout << "4是土技能，消耗18个水晶，同时使敌人的血量除以2（如是奇数就加1再除以2）" << endl;
    while (blood1 > 0 && blood2  > 0 && crystal1 > 0 && crystal2 > 0)
    {
        cout << "1玩家出牌！" << endl;
        cin >> n;
        if (n == 1) {
            blood2 -= 4;
            crystal1 -= 4 * usehalf(1);
        }
        else
        {
            if (n == 2)
            {
                blood2 -= 11;
                crystal1 -= 10 * usehalf(1);
            }
            else
            {
                if (n == 3)
                {
                    blood2 -= 5;
                    crystal1 -= 10 * usehalf(1);
                    half1 = true;
                }
                else
                {
                    if(blood2 % 2 == 0)
                    {
                        blood2 /= 2;
                    }
                    else
                    {
                        blood2 = (blood2 + 1) / 2;
                    }
                    crystal1 -= 18 * usehalf(1);
                }
            }
        }
        cout << blood1 << "  " << blood2 << endl;
        cout << crystal1 << "  " << crystal2 << endl;
        cout << "2玩家出牌！" << endl;
        cin >> n;
        if (n == 1) {
            blood1 -= 4;
            crystal2 -= 4 * usehalf(2);
        }
        else
        {
            if (n == 2)
            {
                blood1 -= 11;
                crystal2 -= 10 * usehalf(2);
            }
            else
            {
                if (n == 3)
                {
                    blood1 -= 5;
                    crystal2 -= 10 * usehalf(2);
                    half2 = true;
                }
                else
                {
                    if(blood1 % 2 == 0)
                    {
                        blood1 /= 2;
                    }
                    else
                    {
                        blood1 = (blood1 + 1) / 2;
                    }
                    crystal1 -= 18 * usehalf(2);
                }
            }
        }
        cout << blood1 << "  " << blood2 << endl;
        cout << crystal1 << "  " << crystal2 << endl;
    }
    if(blood1 || crystal1 == 0)
    {
        cout << "2玩家获胜！" << endl;
    }
    else
    {
        if(blood2 || crystal2 == 0)
        {
            cout << "1玩家获胜！" << endl;
        }
    }
    return 0;
}
