package com.telenav.parlament.model;

import java.util.Arrays;
import java.util.Date;

public class Interpret extends Angajat {
	private int numarLimbiVorbite;
	private String[] limbiVorbite = {"Engleza", "Franceza"};

	public Interpret(int iD, String nume, String adresa, Date dataNasterii, double salariu, int numarLimbiVorbite) {
		super(iD, nume, adresa, dataNasterii, salariu);
		this.numarLimbiVorbite = numarLimbiVorbite;
	}

	public int getNumarLimbiVorbite() {
		return numarLimbiVorbite;
	}

	public void setNumarLimbiVorbite(int numarLimbiVorbite) {
		this.numarLimbiVorbite = numarLimbiVorbite;
	}

	public String[] getLimbiVorbite() {
		return limbiVorbite;
	}

	public void setLimbiVorbite(String[] limbiVorbite) {
		this.limbiVorbite = limbiVorbite;
	}

	@Override
	public String toString() {
		return super.toString() + "Interpret [numarLimbiVorbite=" + numarLimbiVorbite
				+ ", limbiVorbite=" + Arrays.toString(limbiVorbite) + "]";
	}

}
