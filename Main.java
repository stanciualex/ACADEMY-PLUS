package com.telenav.parlament.test;

import java.util.Date;

import com.telenav.parlament.model.Angajat;
import com.telenav.parlament.model.Cadou;
import com.telenav.parlament.model.Parlamentar;
import com.telenav.parlament.model.Interpret;
import com.telenav.parlament.model.Pictura;

public class Main {

	public static void main(String[] args) {
		/*Angajat angajat = new Angajat(1, "Ionescu", "Str. Noua", new Date(), 1000.00);
		Angajat angajat2 = new Angajat(2, "Vasile", "Str. Veche", new Date(), 1200.0);
		Angajat angajat3 = new Angajat(3, "Marinescu", "Str. Da", new Date(), 1240.0);*/
		
		Parlamentar parlamentar = new Parlamentar(1, "Ionescu", "Str. Noua", new Date(), 1000.00, "etica", "drept");
		Parlamentar parlamentar2 = new Parlamentar(2, "Marin", "Str. Rasaritului", new Date(), 1250.0, "etica", "drept");
		Parlamentar parlamentar3 = new Parlamentar(3, "Vasile", "Str. Veche", new Date(), 1120.0, "etica", "drept");
		Parlamentar parlamentar4 = new Parlamentar(4, "Georgescu", "Str. Libertatii", new Date(), 1599.0, "etica", "drept");
		
		Interpret interpret = new Interpret(5, "Georgian", "Str. Dunarii", new Date(), 1221.0, 2);
		Interpret interpret2 = new Interpret(6, "Vasilescu", "Str. Sperantei", new Date(), 1289.0, 2);
		Interpret interpret3 = new Interpret(7, "Marinescu", "Str. Noptii", new Date(), 1604.0, 2);
		Interpret interpret4 = new Interpret(8, "Popescu", "Str. Soarelui", new Date(), 1754.0, 2);
		
		Angajat[] angajat = new Angajat[8];
		angajat[0] = parlamentar;
		angajat[1] = parlamentar2;
		angajat[2] = parlamentar3;
		angajat[3] = parlamentar4;
		angajat[4] = interpret;
		angajat[5] = interpret2;
		angajat[6] = interpret3;
		angajat[7] = interpret4;
		
		
		Cadou[] registru = new Cadou[12];
		
		registru[0] = new Cadou(250.0, "pictura", parlamentar);
		registru[1] = new Cadou(300.0, "PC", parlamentar2);
		registru[2] = new Cadou(560.0, "mobila", parlamentar3);
		registru[3] = new Cadou(5560.0, "masina", parlamentar4);
		registru[4] = new Cadou(4.0, "caiet", parlamentar);
		registru[5] = new Cadou(50.0, "telefon", parlamentar2);
		registru[6] = new Cadou(250.0, "tableta", interpret);
		registru[7] = new Cadou(56.0, "casti", interpret2);
		registru[8] = new Cadou(100.0, "caciula", interpret3);
		registru[9] = new Cadou(854.0, "costum", interpret4);
		registru[10] = new Cadou(540.0, "pantofi", interpret);
		registru[11] = new Cadou(590.0, "pictura", interpret2);
		
		Pictura[] picturi = new Pictura[2];
		
		Pictura pictura = new Pictura(250.0, "pictura", parlamentar, "Leonardo Da Vinci", 1856, false);
		Pictura pictura2 = new Pictura(590.0, "pictura", interpret2, "Nicolae Grigorescu", 1852, true);
		
		picturi[0] = pictura;
		picturi[1] = pictura2;
		
		int[] freq = new int[9];
		int maxim = -1;
		
		for (Cadou cadou : registru){
			freq[cadou.getAngajat().getID()]++;
			if (freq[cadou.getAngajat().getID()] > maxim)
				maxim = freq[cadou.getAngajat().getID()];
		}
		
		for (int i = 1; i < 9; i++){
			if (freq[i] == maxim){
				System.out.println(angajat[i]);
			}
		}
		
		int numarTablouriOriginale = 0;
		
		for (int i = 0; i < 2; i++){
			if (picturi[i].getOriginal() == true)
				numarTablouriOriginale++;
		}
		
		System.out.println();
		System.out.println("Numarul tablourilor originale este " + numarTablouriOriginale);
		System.out.println();
	
		
		
	//	System.out.println(cadou);//Se apeleaza automat metoda toString din clasa angajat
		
		/*double suma = 0;
		for (Cadou cadou : registru) {
			System.out.println(cadou);
			if (cadou.getAngajat().getID() == 7)
				suma += cadou.getValoare();
		}
		System.out.println("Suma totala: " + suma);*/
	}

}
