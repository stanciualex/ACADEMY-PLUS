package com.telenav.parlament.model;

import java.util.Date;

public class Angajat {
	private int ID;
	private String nume;
	private String adresa;
	private Date dataNasterii;
	private double salariu;
	
	/**
	 * @param iD
	 * @param nume
	 * @param adresa
	 * @param dataNasterii
	 * @param salariu
	 */
	public Angajat(int iD, String nume, String adresa, Date dataNasterii, double salariu) {
		super();
		ID = iD;
		this.nume = nume;
		this.adresa = adresa;
		this.dataNasterii = dataNasterii;
		this.salariu = salariu;
	}

	/**
	 * 
	 */
	public Angajat() {
		super();
	}

	public int getID() {
		return ID;
	}

	public void setID(int iD) {
		ID = iD;
	}

	public String getNume() {
		return nume;
	}

	public void setNume(String nume) {
		this.nume = nume;
	}

	public String getAdresa() {
		return adresa;
	}

	public void setAdresa(String adresa) {
		this.adresa = adresa;
	}

	public Date getDataNasterii() {
		return dataNasterii;
	}

	public void setDataNasterii(Date dataNasterii) {
		this.dataNasterii = dataNasterii;
	}

	public double getSalariu() {
		return salariu;
	}

	public void setSalariu(double salariu) {
		this.salariu = salariu;
	}

	@Override
	public String toString() {
		return "Angajat [ID=" + ID + ", nume=" + nume + ", adresa=" + adresa + ", dataNasterii=" + dataNasterii
				+ ", salariu=" + salariu + "]";
	}
	
	
}
