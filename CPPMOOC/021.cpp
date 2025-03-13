//OJ_CPPMOOC_021
//魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
//红司令部，City 1，City 2，……，City n，蓝司令部
//两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
//有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
//双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。
//
//不同的武士有不同的特点。
//dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
//dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
//ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
//iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
//lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
//wolf没特点。
//请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。
//
//武士在刚降生的时候有一个生命值。
//在每个整点，双方的司令部中各有一个武士降生。
//红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。
//蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。
//制造武士需要生命元。
//制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。
//如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
//给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
//一共有两种事件，其对应的输出样例如下：
//
//1) 武士降生
//输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
//表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。
//(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
//如果造出的是dragon，那么还要输出一行，例：
//It has a arrow,and it's morale is 23.34
//表示该dragon降生时得到了arrow,其士气是23.34
//（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
//如果造出的是ninja，那么还要输出一行，例：
//It has a bomb and a arrow
//表示该ninja降生时得到了bomb和arrow。
//如果造出的是iceman，那么还要输出一行，例：
//It has a sword
//表示该iceman降生时得到了sword。
//如果造出的是lion，那么还要输出一行，例：
//It's loyalty is 24
//表示该lion降生时的忠诚度是24。
//2) 司令部停止制造武士
//输出样例： 010 red headquarter stops making warriors
//表示在 10点整，红方司令部停止制造武士
//
//输出事件时：
//首先按时间顺序输出；
//同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

//declaration
class Soldier {
 public:
  string soldier_type_array_[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
  unsigned int soldier_born_blood_array_[5] = {0, 0, 0, 0, 0};
  unsigned int soldier_born_blood_array_user_[5] = {0, 0, 0, 0, 0};
  unsigned int soldier_strength_array_[5] = {0, 0, 0, 0, 0};
  unsigned int soldier_alive_[5] = {0, 0, 0, 0, 0};
  const string soldier_weapon_[3] = {"sword", "bomb", "arrow"};
  float dragon_morale_ = 0;
  unsigned int lion_loyalty_ = 0;
  unsigned int soldier_id_ = 0;

  unsigned int GetSoldierMinBornBlood();
  void SetSoldierBornBlood(int soldier_army_type);
  void SoldierSettingInit(int soldier_army_type);
  void AddSoldierAlive(int soldier_index);
  void GetSoldierBornBlood();

  Soldier();
  ~Soldier();
 protected:

 private:
  unsigned int soldier_min_born_blood_ = 0;

  void SetSoldierMinBornBlood();
  void SetSoldierStrength();
};
class ArmyBase {
 public:
  unsigned int headquarter_blood_ = 0, army_type_ = 0; // army_type_: 0-red, 1-blue
  int soldier_index_last_ = -1; // does not pruduce the soldier
  int base_stop_produce_ = false;
  string army_name_ = "red";
  static unsigned int time_h_;
  Soldier army;

  int ProduceSoldier();
  void ArmyBaseInit();
  void ArmyPrint(int production_result);
  void GetHeadquarterBloodFromUser();

  ArmyBase(unsigned int army_type);
 protected:
 private:
};

//define
Soldier::Soldier() {
}
Soldier::~Soldier() {
  //do nothing
}
unsigned int Soldier::GetSoldierMinBornBlood() {
  return soldier_min_born_blood_;
}
void Soldier::SetSoldierMinBornBlood() {
  soldier_min_born_blood_ = soldier_born_blood_array_[0];
  for (int i = 1; i < 5; ++i) {
    if (soldier_min_born_blood_ > soldier_born_blood_array_[i]) {
      soldier_min_born_blood_ = soldier_born_blood_array_[i];
    } else {
    }
  }
}
void Soldier::GetSoldierBornBlood() {
  for (int i = 0; i < 5; ++i) {
    cin >> soldier_born_blood_array_user_[i];
  }
}
void Soldier::SetSoldierBornBlood(int soldier_army_type) {
//  unsigned int soldier_born_blood_array[5] = {0, 0 , 0, 0, 0};
//  for (int i = 0; i < 5; ++i) {
//    cin >> soldier_born_blood_array[i];
//  }
  if (soldier_army_type == 1) {
    // Blue soldier army blood
    soldier_born_blood_array_[0] = soldier_born_blood_array_user_[3];
    soldier_born_blood_array_[1] = soldier_born_blood_array_user_[0];
    soldier_born_blood_array_[2] = soldier_born_blood_array_user_[1];
    soldier_born_blood_array_[3] = soldier_born_blood_array_user_[2];
    soldier_born_blood_array_[4] = soldier_born_blood_array_user_[4];
  } else {
    // Red solider army blood
    soldier_born_blood_array_[0] = soldier_born_blood_array_user_[2];
    soldier_born_blood_array_[1] = soldier_born_blood_array_user_[3];
    soldier_born_blood_array_[2] = soldier_born_blood_array_user_[4];
    soldier_born_blood_array_[3] = soldier_born_blood_array_user_[1];
    soldier_born_blood_array_[4] = soldier_born_blood_array_user_[0];
  }
}
void Soldier::SetSoldierStrength() {
  for (int i = 0; i < 5; ++i) {
    soldier_strength_array_[i] = soldier_born_blood_array_[i];
  }
}
void Soldier::SoldierSettingInit(int soldier_army_type) {
  if (soldier_army_type == 1) {
    //Blue Soldier Army
    //Soldier type
    soldier_type_array_[0] = "lion";
    soldier_type_array_[1] = "dragon";
    soldier_type_array_[2] = "ninja";
    soldier_type_array_[3] = "iceman";
    soldier_type_array_[4] = "wolf";
  } else {
    // Red Soldier Army
    // Soldier type
    soldier_type_array_[0] = "iceman";
    soldier_type_array_[1] = "lion";
    soldier_type_array_[2] = "wolf";
    soldier_type_array_[3] = "ninja";
    soldier_type_array_[4] = "dragon";
  }
  // Soldier ID
  soldier_id_ = 0;
  // Soldier born blood
  SetSoldierBornBlood(soldier_army_type);
  SetSoldierStrength();
  // Soldier use the default value
  SetSoldierMinBornBlood();
  // soldier_alive_
  for (int i = 0; i < 5; ++i) {
    soldier_alive_[i] = 0;
  }
  // dragon morale
  dragon_morale_ = 0;
  // lion loyalty
  lion_loyalty_ = 0;
}
void Soldier::AddSoldierAlive(int soldier_index) {
  soldier_id_++;
  soldier_alive_[soldier_index]++;
}
int ArmyBase::ProduceSoldier() {
  for (int i = soldier_index_last_ + 1;
       headquarter_blood_ >= army.GetSoldierMinBornBlood(); ++i) {
    i %= 5;
    if (headquarter_blood_ >= army.soldier_born_blood_array_[i]) {
      headquarter_blood_ -= army.soldier_born_blood_array_[i];
      army.AddSoldierAlive(i);
      soldier_index_last_ = i;
      // soldier special attributes
      if (army.soldier_type_array_[soldier_index_last_] == "dragon") {
        army.dragon_morale_ = (float) headquarter_blood_
            / army.soldier_born_blood_array_[soldier_index_last_];
      } else if (army.soldier_type_array_[soldier_index_last_] == "lion") {
        army.lion_loyalty_ = headquarter_blood_;
      }
      return 0;
    } else {
    }
  }
  return 1;
}
ArmyBase::ArmyBase(unsigned int army_type) {
  army_type_ = army_type;
  if (army_type == 1) {
    army_name_ = "blue";
  } else {
    army_name_ = "red";
  }
}
void ArmyBase::ArmyBaseInit() {
  ArmyBase::time_h_ = 0;
  soldier_index_last_ = -1;
  base_stop_produce_ = false;
  army.SoldierSettingInit(army_type_);
}
void ArmyBase::GetHeadquarterBloodFromUser() {
  cin >> headquarter_blood_;
}
void ArmyBase::ArmyPrint(int production_result) {
  if (production_result == 0) {
    // print soldier
    // cout format: 000 red iceman 1 born with strength 5,1 iceman in red headquarter
//    cout.width(3);
//    cout.fill('0');
    cout << setfill('0') << setw(3) << ArmyBase::time_h_ << " " << army_name_ << " "
         << army.soldier_type_array_[soldier_index_last_] << " "
         << army.soldier_id_ << " born with strength "
         << army.soldier_strength_array_[soldier_index_last_] << ","
         << army.soldier_alive_[soldier_index_last_] << " "
         << army.soldier_type_array_[soldier_index_last_] << " in "
         << army_name_ << " headquarter" << endl;
    // print soldier special attributes
    if (army.soldier_type_array_[soldier_index_last_] == "dragon") {
      // dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
      // dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
      // cout sample:It has a arrow,and it's morale is 23.34
      cout << "It has a " << army.soldier_weapon_[army.soldier_id_ % 3]
           << ",and it's morale is " << setiosflags(ios::fixed)
           << setprecision(2) << army.dragon_morale_ << endl;
    } else if (army.soldier_type_array_[soldier_index_last_] == "ninja") {
      // ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
      // cout sample:It has a bomb and a arrow
      cout << "It has a " << army.soldier_weapon_[army.soldier_id_ % 3]
           << " and a " << army.soldier_weapon_[(army.soldier_id_ + 1) % 3]
           << endl;
    } else if (army.soldier_type_array_[soldier_index_last_] == "iceman") {
      // iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
      // cout sample:It has a sword
      cout << "It has a " << army.soldier_weapon_[army.soldier_id_ % 3] << endl;
    } else if (army.soldier_type_array_[soldier_index_last_] == "lion") {
      // lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
      // cout sample:It's loyalty is 24
      cout << "It's loyalty is " << army.lion_loyalty_ << endl;
    } else {}
  } else if (production_result == 1) {
    // cout format: 004 blue headquarter stops making warriors
    cout.width(3);
    cout.fill('0');
    cout << ArmyBase::time_h_ << " " << army_name_ << " headquarter stops making warriors"
         << endl;
  } else {
  }
}

unsigned int ArmyBase::time_h_ = 0;

int main() {
  ArmyBase red(0), blue(1);
  unsigned int test_num = 0, test_case =1;
  cin >> test_num;
  while(test_num) {
//    cout << "Case:" << test_case << endl;
    red.GetHeadquarterBloodFromUser();
    red.army.GetSoldierBornBlood();
    blue.headquarter_blood_ = red.headquarter_blood_;
    memset(blue.army.soldier_born_blood_array_user_, 0, sizeof(unsigned int)*5);
    memcpy(blue.army.soldier_born_blood_array_user_,
           red.army.soldier_born_blood_array_user_,
           sizeof(unsigned int)*5);
    red.ArmyBaseInit();
    blue.ArmyBaseInit();
    cout << "Case:" << test_case << endl;
    while((!red.base_stop_produce_) || (!blue.base_stop_produce_)) {
      if(!red.base_stop_produce_) {
        red.base_stop_produce_ = red.ProduceSoldier();
        red.ArmyPrint(red.base_stop_produce_);
      } else {
      }
      if(!blue.base_stop_produce_) {
        blue.base_stop_produce_ = blue.ProduceSoldier();
        blue.ArmyPrint(blue.base_stop_produce_);
      } else {
      }
      ArmyBase::time_h_++;
    }
    test_num--;
    test_case++;
  }
  return 0;
}