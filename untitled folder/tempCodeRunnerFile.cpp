void PrintAllMembersData(vector<stMember> vMembers){
    cout<<"\n\t\t\t\t\tMember List ("<<vMembers.size()<<") Member(s).";
    cout<<"\n-----------------------------------------------------------";
    cout<<"-------------------------------------------------------------\n";
    cout <<"| " << left << setw(15) << "Member ID";
    cout <<"| " << left << setw(30) << "Member Name";
    cout <<"| " << left << setw(12) << "Phone";
    cout <<"| " << left << setw(12) << "Age";

    cout<<"\n-----------------------------------------------------------";
    cout<<"-------------------------------------------------------------\n";

    for (stMember Member : vMembers)
    {
        PrintMemberCard(Member);
        cout<<endl;
    }

    cout<<"\n-----------------------------------------------------------";
    cout<<"-------------------------------------------------------------\n";

    
}
