#include <iostream> 
#include <limits> 
#include <bits/stdc++.h> 
#include <string>

using namespace std;
void sortArr(int arr[], int n)
{
    //sakht instance az class vector baraaye estefade az method haye on
	vector<pair<int, int> > vp;
	for (int i = 0; i < n; ++i) {
	    //ersal maghadiri ke dar vorodi func sort gerefte shode ke da halghe index array va value on dade shode
		vp.push_back(make_pair(arr[i], i));
	}
	//peykar bandi func sort 
	sort(vp.begin(), vp.end());
	cout << " verifier\t"
		<< "tedad gharardad" << endl;
	//namayesh shomare verifayer sort shode tavasot tedad gharardad oo ke ta zamani ejra mshavad ke verifayer bashad
	for (int i = 1; i <= vp.size(); i++) {
	    int s = vp[i-1].second;
	    int f = vp[i-1].first;
	    cout<<endl;
	    //joda sazi verifayer haii ke kar nakardan az verifayer haii ke kar kardan 
	    if(f == 0){
	        cout <<" "<<s+1 << "\t\t"
			<< f<< endl;
	        cout<<"*************************"<<endl;
	    }else{
	        cout <<" "<<s+1 << "\t\t"
			<< f<< endl;
	    }
	}
}
int main()
{
    //tedad verifayer
    const int tedad_conf_defa = 5 ,tedad_conf_etelaat = 4 ,tedad_conf_omor = 3 ;
    //value haye moteghayer dar gharardad
    int random, i, tedad_gharardad = 0, count = 8, total = 0,n;
    double mohasebeh_darsad;
    int tekrar_barname = 0;
    //pass vezarat khaneh
    string pass , pass_defa = "defa" ,pass_etelaat = "etela", pass_kharej = "kharej"; // pass kharej ,etela ,defa
    //dar khat zir tedad tekrar in farayand mibashad ke 12 bar kol barnameh tekrar mishavad ke mitvan on ra ta bi nahayat kard
    for (tekrar_barname ; tekrar_barname<12 ;tekrar_barname++){
            //gereftane tedad verifier
            cout <<"tedad verifier ra vared konid? (bish az 1 bashad) : ";
            cin>>count;
            cout<<endl;
            //dar if check shode ast ke agar vorodi adad bod farayand zir edameh barnameh bashad ke jodaye vezarat khaneh ast 
            if (cin.good())
            {
                //sakht array baraye zakhire value va peymayesh bein maghadir
                int dice[count] = {0};
                cout << "chand ta gharardad darim ?" << endl;
                cin >> tedad_gharardad;
                cout <<endl<<endl;
                //estefade az func random
                srand(unsigned(time(0)));
                //halghe ii ke ba tavajoh be tedade gharardad ejra shode va be har verifier toye har ejra gharardad takhsis midahad
                for(i = 0; i < tedad_gharardad; i++) 
                {
                    random = rand() % count;
                    dice[random]++;
                }
                //halghe ii ke baraye namayesh verifier ha ba tavajoh be maghadiri ke daryaft kardan ejra mishavad
                for(int k = 1; k <= count; k++)
                {
                    cout << " number " << k << " be tedade " << dice[k-1] << " bar entekhab shod" << endl;
                }
                cout<<"================================================"<<endl;
                //halghe ii ke baraye mohasebeh darsad kar kard har verifier be kar miravad va majmooe darsad ra ba tavajoh be zarfiat verifier ha mohasebeh mikonad
                for(int b = 1; b <= count ; b++)
                {
                    mohasebeh_darsad = (double)dice[b-1]*100/count ;
                    n = sizeof(dice) / sizeof(dice[b-1]);
                    cout << " number " << b << " be meghdar " << mohasebeh_darsad << "% az tedad kol verifier ha entekhab shod" << endl;
                    total+=mohasebeh_darsad;
                }
                cout<<"================================================"<<endl;
                //natije giri baraye inke ba tavajoh be tedad verifier ha cheghadr az zarfiat estefade va cheghadr khali mandeh ast
                if(total<=100&&total>96){
                    cout << " az zarfiat verifier ha kamel estefade shode ast."<<endl;
                }else if(total<96){
                    cout << " az zarfiat verifier ha baghi mande ast."<<endl;
                }
                else{
                    cout << " be meghdar "<<total-100<<"% bish az zarfiat verifier gharardad baste shode ast ."<<endl;
                }
                cout<<"================================================"<<endl;
                //initialize func sort array
	            sortArr(dice, n);
	            cout<<endl;
            }
            else
            {
                // agar da vorodi be jaye adda yek character vared konim password vezarat khaneh ra daryaft mikonad
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"password ra vared konid : (confirm pass) ";
                cin>> pass;
                cout<<endl;
                //edameh barnameh ba tavajoh be pass har vezarat khaneh albate ba tedad verifier sabet va joda az barnameh asli
                if(pass == pass_defa){
                    //mesle comment haye barnameh asli mibashad faghat ba tafavote tedad verifier sabet ke dar ebteda barnameh meghdar dehi shodan
                    int dice[tedad_conf_defa] = {0};
                    cout << "chand ta gharardad darim ?" << endl;
                    cin >> tedad_gharardad;
                    cout <<endl<<endl;
                    srand(unsigned(time(0)));
                    for(i = 0; i < tedad_gharardad; i++) 
                    {
                        random = rand() % tedad_conf_defa;
                        dice[random]++;
                    }
                    for(int k = 1; k <= tedad_conf_defa; k++)
                    {
                        cout << " number " << k << " be tedade " << dice[k-1] << " bar entekhab shod" << endl;
                    }
                    cout<<"================================================"<<endl;
                    
                    for(int b = 1; b <= tedad_conf_defa ; b++)
                    {
                        
                        mohasebeh_darsad = (double)dice[b-1]*100/tedad_conf_defa ;
                        n = sizeof(dice) / sizeof(dice[b-1]);
                        cout << " number " << b << " be meghdar " << mohasebeh_darsad << "% az tedad kol verifier ha entekhab shod" << endl;
                        total+=mohasebeh_darsad;
                        
                    }
                    cout<<"================================================"<<endl;
                    if(total<=100&&total>96){
                        cout << " az zarfiat verifier ha kamel estefade shode ast."<<endl;
                    }else if(total<96){
                        cout << " az zarfiat verifier ha baghi mande ast."<<endl;
                    }
                    else{
                        cout << " be meghdar "<<total-100<<"% bish az zarfiat verifier gharardad baste shode ast ."<<endl;
                    }
                    cout<<"================================================"<<endl;
                    sortArr(dice, n);
                    cout<<endl;
                }else if(pass == pass_etelaat){
                    int dice[tedad_conf_etelaat] = {0};
                    cout << "chand ta gharardad darim ?" << endl;
                    cin >> tedad_gharardad;
                    cout <<endl<<endl;
                    srand(unsigned(time(0)));
                    for(i = 0; i < tedad_gharardad; i++) 
                    {
                        random = rand() % tedad_conf_etelaat;
                        dice[random]++;
                    }
                    for(int k = 1; k <= tedad_conf_etelaat; k++)
                    {
                        cout << " number " << k << " be tedade " << dice[k-1] << " bar entekhab shod" << endl;
                    }
                    cout<<"================================================"<<endl;
                    
                    for(int b = 1; b <= tedad_conf_etelaat ; b++)
                    {
                        
                        mohasebeh_darsad = (double)dice[b-1]*100/tedad_conf_etelaat ;
                        n = sizeof(dice) / sizeof(dice[b-1]);
                        cout << " number " << b << " be meghdar " << mohasebeh_darsad << "% az tedad kol verifier ha entekhab shod" << endl;
                        total+=mohasebeh_darsad;
                        
                    }
                    cout<<"================================================"<<endl;
                    if(total<=100&&total>96){
                        cout << " az zarfiat verifier ha kamel estefade shode ast."<<endl;
                    }else if(total<96){
                        cout << " az zarfiat verifier ha baghi mande ast."<<endl;
                    }
                    else{
                        cout << " be meghdar "<<total-100<<"% bish az zarfiat verifier gharardad baste shode ast ."<<endl;
                    }
                    cout<<"================================================"<<endl;
                    sortArr(dice, n);
                    cout<<endl;
                }else if(pass == pass_kharej){
                    int dice[tedad_conf_omor] = {0};
                    cout << "chand ta gharardad darim ?" << endl;
                    cin >> tedad_gharardad;
                    cout <<endl<<endl;
                    srand(unsigned(time(0)));
                    for(i = 0; i < tedad_conf_omor; i++) 
                    {
                        random = rand() % tedad_conf_omor;
                        dice[random]++;
                    }
                    for(int k = 1; k <= tedad_conf_omor; k++)
                    {
                        cout << " number " << k << " be tedade " << dice[k-1] << " bar entekhab shod" << endl;
                    }
                    cout<<"================================================"<<endl;
                    
                    for(int b = 1; b <= tedad_conf_omor ; b++)
                    {
                        
                        mohasebeh_darsad = (double)dice[b-1]*100/tedad_conf_omor ;
                        n = sizeof(dice) / sizeof(dice[b-1]);
                        cout << " number " << b << " be meghdar " << mohasebeh_darsad << "% az tedad kol verifier ha entekhab shod" << endl;
                        total+=mohasebeh_darsad;
                        
                    }
                    cout<<"================================================"<<endl;
                    if(total<=100&&total>96){
                        cout << " az zarfiat verifier ha kamel estefade shode ast."<<endl;
                    }else if(total<96){
                        cout << " az zarfiat verifier ha baghi mande ast."<<endl;
                    }
                    else{
                        cout << " be meghdar "<<total-100<<"% bish az zarfiat verifier gharardad baste shode ast ."<<endl;
                    }
                    cout<<"================================================"<<endl;
                    sortArr(dice, n);
                    cout<<endl;
                }
                //check kardan vorodi password agar nadorost bashad
                else{
                    cout<<"passord na dorost !"<<endl; 
                }     
            }
    }    
    return 0;
}