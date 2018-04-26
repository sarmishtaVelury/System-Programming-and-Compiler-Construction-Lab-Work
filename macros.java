import java.util.*;
import java.io.*;

class macros {
	public static void main(String[] args) throws IOException {
		
		int mntc=0,mdtc=0,plac=0,clac=0;
		String[] mnTable = new String[30];
		String[] mdTable = new String[30];
		String[] plaTable = new String[30];
		String[] claTable = new String[30];
		String[] macroNameTable = new String[30];
		String[] argNames;
		String[] argArray;

		BufferedReader br = new BufferedReader(new FileReader("inputmacros.txt"));
		BufferedWriter mntFile = new BufferedWriter(new FileWriter("mnt.txt",true));
		BufferedWriter mdtFile = new BufferedWriter(new FileWriter("mdt.txt",true));
		BufferedWriter claFile = new BufferedWriter(new FileWriter("cla.txt",true));
		BufferedWriter plaFile = new BufferedWriter(new FileWriter("pla.txt",true));

		String temp="";
		String macroname="";
		String[] linearArray;
		int i,j,flag=0;

		while((temp = br.readLine())!=null) {
			System.out.println(temp);

			for(i=0;i<mntc;i++) {
				System.out.println("Inside for loop for CLA Table");
				if(temp.contains(macroNameTable[i])) {
					System.out.println("Inside if for CLA Table");
					argArray = temp.split(" ");
					argNames = argArray[1].split(",");
					for(j=0;j<argNames.length;j++) {
						System.out.println("Adding arg names to CLA Table");
						claTable[clac] = argNames[j];
						claFile.write(claTable[clac]);
						claFile.newLine();
						clac++;
					}
					break;
				}
			}

			if(flag==1) {
				System.out.println("Macro definition line");
				mdTable[mdtc] = mdtc + "  " + temp;
				mdtFile.write(mdTable[mdtc]);
				mdtFile.newLine();
				mdtc++;
				if(temp.contains("MEND")) {
					System.out.println("Macro definition ended");
					flag=0;
				}
			}
			
			if(temp.contains("MACRO")) {
				System.out.println("Macro declared");
				flag=1;
				temp = temp.replace(",","");
				linearArray = temp.split(" ");
				macroname = linearArray[1];
				macroNameTable[mntc] = macroname;
				mnTable[mntc] = mntc + "  " + macroname + "  " + mdtc;
				mntFile.write(mnTable[mntc]);
				mntFile.newLine();
				mntc++;
				for(i=2;i<linearArray.length;i++) {
					System.out.println("Macro argument added");
					plaTable[plac] = plac + "  " + linearArray[i];
					plaFile.write(plaTable[plac]);
					plaFile.newLine();
					plac++;					
				}
			}

		}

		System.out.println("ALL TABLES:  ");
		System.out.println("MNT TABLE");
		for(i=0;i<mntc;i++)
			System.out.println(mnTable[i]);
		System.out.println("MDT TABLE");
		for(i=0;i<mdtc;i++)
			System.out.println(mdTable[i]);
		System.out.println("PLA TABLE");
		for(i=0;i<plac;i++)
			System.out.println(plaTable[i]);
		System.out.println("CLA TABLE");
		for(i=0;i<clac;i++)
			System.out.println(claTable[i]);

		br.close();
		mntFile.close();
		mdtFile.close();
		plaFile.close();
		claFile.close();
	}
}


/*
OUTPUT
C:\Users\Niti123\Desktop\coding\spcc>javac macroTry.java
C:\Users\Niti123\Desktop\coding\spcc>java macroTry
ALL TABLES:
MNT TABLE
0  MAC1  0
1  MAC2  4
MDT TABLE
0  LOAD A,&ARG1
1  ADD B,&ARG2
2  STORE C,&ARG3
3  MEND
4  ADD A,&ARG2
5  MEND
PLA TABLE
0  &ARG
1  &ARG
2  &ARG3
3  &AR
4  &ARG2
CLA TABLE
3
4
5
1
2
*/