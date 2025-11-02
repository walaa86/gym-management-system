#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
#include <limits>
#include <fstream>
using namespace std;

const string MembersFileName = "Members.txt";

struct stMember{
    string MemberId = "";
    string Name = "";
    string Phone = "";
    int Age = 0;
    bool MarkForDelet = false;
};

// ========== الدوال الأساسية (بالترتيب الصحيح) ==========

vector<string> SplitString(string S1, string Delimiator){
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delimiator)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
           vString.push_back(sWord);
        }
        S1.erase(0, pos + Delimiator.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

stMember ConvertLineToRecord(string Line, string Separator = "#//#"){
    stMember Member;
    vector<string> vMemeberData;

    vMemeberData = SplitString(Line, Separator);

    if (vMemeberData.size() >= 4) {
        Member.MemberId = vMemeberData[0];
        Member.Name = vMemeberData[1];
        Member.Phone = vMemeberData[2];
        
        try {
            Member.Age = stoi(vMemeberData[3]);
        } catch (...) {
            Member.Age = 0;
        }
    }

    return Member;
}

string ConvertRecordToLine(stMember Member, string Seperator = "#//#"){
    string stMemberRecord = "";

    stMemberRecord += Member.MemberId + Seperator;
    stMemberRecord += Member.Name + Seperator;
    stMemberRecord += Member.Phone + Seperator;
    stMemberRecord += to_string(Member.Age);

    return stMemberRecord;
}

bool IsMemberExists(string MemberID, string FileName){
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    
    if (MyFile.is_open()){
        string Line;
        stMember Member;
        
        while (getline(MyFile, Line)){
            Member = ConvertLineToRecord(Line);
            if (Member.MemberId == MemberID){
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    
    return false;
}

// ========== دوال القراءة والإدخال ==========

stMember ReadNewMember(){
    stMember Member;
    
    cout << "Enter Member ID ? ";
    getline(cin >> ws, Member.MemberId);
    
    while (IsMemberExists(Member.MemberId, MembersFileName)){
        cout << "\nMember with [" << Member.MemberId << "] already exists!";
        cout << "\nEnter another Member ID ? ";
        getline(cin >> ws, Member.MemberId);
    }
    
    cout << "Enter Member Name? ";
    getline(cin, Member.Name);
    
    cout << "Enter Phone ? ";
    getline(cin, Member.Phone);
    
    cout << "Enter Age? ";
    cin >> Member.Age;
    cin.ignore();
    
    return Member;
}

string ReadMemberID(){
    string MemberID = "";
    cout << "\nPlease enter MemberID ? ";
    cin >> MemberID;
    return MemberID;
}

// ========== دوال التعامل مع الملفات ==========

vector<stMember> LoadMembersDataFromFile(string FileName){
    vector<stMember> vMember;
    fstream MyFile; 
    MyFile.open(FileName, ios::in);
    
    if (MyFile.is_open())
    {
        string Line;
        stMember Member;
        while (getline(MyFile, Line))
        {
            Member = ConvertLineToRecord(Line);
            vMember.push_back(Member);
        }
        MyFile.close();
    }
    
    return vMember;
}

vector<stMember> SaveMemberDatatoFile(string FileName, vector<stMember> vMembers){
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    
    if (MyFile.is_open())
    {
        for (stMember M : vMembers)
        {
            if (M.MarkForDelet == false)
            {
               DataLine = ConvertRecordToLine(M);
               MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vMembers;
}

void AddDataLineToFile(string FileName, string DataLine){
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    
    if (MyFile.is_open()){
        MyFile << DataLine << endl;
        MyFile.close();
    }
}

// ========== دوال البحث ==========

bool FindMemberByMemberID(string MemberID, vector<stMember> vMembers, stMember &Member){
    for (stMember M : vMembers)
    {
        if (M.MemberId == MemberID)
        {
            Member = M;
            return true;
        }
    }
    return false;
}

// ========== دوال الطباعة ==========

void PrintMemberCard(stMember MemberCard){
    cout << "| " << left << setw(15) << MemberCard.MemberId;
    cout << "| " << left << setw(30) << MemberCard.Name;
    cout << "| " << left << setw(12) << MemberCard.Phone;
    cout << "| " << left << setw(12) << MemberCard.Age;
}

void PrintAllMembersData(vector<stMember> vMembers){
    cout << "\n\t\t\t\t\tMember List (" << vMembers.size() << ") Member(s).";
    cout << "\n-----------------------------------------------------------";
    cout << "-------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Member ID";
    cout << "| " << left << setw(30) << "Member Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Age";

    cout << "\n-----------------------------------------------------------";
    cout << "-------------------------------------------------------------\n";

    for (stMember Member : vMembers)
    {
        PrintMemberCard(Member);
        cout << endl;
    }

    cout << "\n-----------------------------------------------------------";
    cout << "-------------------------------------------------------------\n";
}

// ========== دوال الإضافة ==========

void AddNewMember(){
    stMember Member;
    Member = ReadNewMember();
    AddDataLineToFile(MembersFileName, ConvertRecordToLine(Member));
}

void AddMembers(){
    char AddMore = 'Y';
    do
    {
        system("clear");
        cout << "Adding New Member : \n\n";
        AddNewMember();
        cout << "\nMember Added Successfully, do you want to add more members? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

// ========== دوال الحذف ==========

bool MarkMemberForDeleteByMemberID(string MemberID, vector<stMember>& vMembers){
    for (stMember &M : vMembers)
    {
        if (M.MemberId == MemberID)
        {
            M.MarkForDelet = true;
            return true;
        }
    }
    return false;
}

bool DeletClientByMemberID(string MemberID, vector<stMember> &vMembers){
    stMember Member;
    char Answer = 'n';
    
    if (FindMemberByMemberID(MemberID, vMembers, Member))
    {
        PrintMemberCard(Member);
        cout << "\n\nAre you sure you want to delete member? y/n ? ";
        cin >> Answer;
        
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkMemberForDeleteByMemberID(MemberID, vMembers);
            SaveMemberDatatoFile(MembersFileName, vMembers);
            vMembers = LoadMembersDataFromFile(MembersFileName);
            cout << "\n\nMember Deleted Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nMember With MemberID (" << MemberID << ") is Not Found\n";
        return false;
    }
    
    return false;
}

// ========== دوال التعديل ==========

stMember ChangeMemberRecod(string MemberID){
    stMember Member;
    Member.MemberId = MemberID;
    
    cout << "\nEnter Member Name? ";
    getline(cin >> ws, Member.Name);

    cout << "Enter Phone ? ";
    getline(cin, Member.Phone);

    cout << "Enter Age? ";
    cin >> Member.Age;
    cin.ignore();

    return Member;
}

bool UpDateClientByMemberID(string MemberID, vector<stMember> &vMembers){
    stMember Member;
    char Answer = 'n';
    
    if (FindMemberByMemberID(MemberID, vMembers, Member))
    {
        PrintMemberCard(Member);
        cout << "\n\nAre you sure you want to update member? y/n ? ";
        cin >> Answer;
        
        if (Answer == 'y' || Answer == 'Y')
        {
            for (stMember &M : vMembers)
            {
                if (M.MemberId == MemberID)
                {
                    M = ChangeMemberRecod(MemberID);
                    break;
                }
            }
            
            SaveMemberDatatoFile(MembersFileName, vMembers);
            vMembers = LoadMembersDataFromFile(MembersFileName);
            cout << "\n\nMember updated Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nMember With MemberID (" << MemberID << ") is Not Found\n";
        return false;
    }
    
    return false;
}

// ========== دوال القائمة الرئيسية ==========

void ShowMainMenu(){
    system("clear");
    cout << "\n======================================\n";
    cout << "\t\tMain Menu\n";
    cout << "======================================\n";
    cout << "[1] Show All Members" << endl;
    cout << "[2] Add New Member" << endl;
    cout << "[3] Delete Member" << endl;
    cout << "[4] Update Member" << endl;
    cout << "[5] Search For Member" << endl;
    cout << "[6] Exit" << endl;
    cout << "======================================\n";
}

int ReadMenuChoice(){
    int Choice;
    cout << "Choose option [1-6]? ";
    cin >> Choice;
    return Choice;
}

void PerformMenuChoice(int choice){
    vector<stMember> vMembers = LoadMembersDataFromFile(MembersFileName);
    string MemberID;
    stMember Member;

    switch (choice)
    {
    case 1:
        PrintAllMembersData(vMembers);
        break;

    case 2:
        AddNewMember();
        break;
        
    case 3:
        MemberID = ReadMemberID();
        DeletClientByMemberID(MemberID, vMembers);
        break;
        
    case 4:
        MemberID = ReadMemberID();
        UpDateClientByMemberID(MemberID, vMembers);
        break;
        
    case 5:
        MemberID = ReadMemberID();
        if (FindMemberByMemberID(MemberID, vMembers, Member))
        {
            PrintMemberCard(Member);
            cout << endl;
        }
        else
        {
            cout << "\nMember not found!\n";
        }
        break;
        
    case 6:
        cout << "\nThank you for using Gym Management System!\n";
        break;
        
    default:
        cout << "\nInvalid choice! Please try again.\n";
        break;
    }
}

// ========== البرنامج الرئيسي ==========

int main(){
    int choice = 0;
    
    do {
        ShowMainMenu();
        choice = ReadMenuChoice();
        PerformMenuChoice(choice);
        
        if (choice != 6) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 6);
    
    return 0;
}