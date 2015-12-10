package com.telenav.parlament.model;

public class Cadou {
	private double valoare;
	private String denumire;
	private Angajat angajat;//Agregare
	/**
	 * @param valoare
	 * @param denumire
	 * @param angajat
	 */
	public Cadou(double valoare, String denumire, Angajat angajat) {
		super();
		this.valoare = valoare;
		this.denumire = denumire;
		this.angajat = angajat;
	}
	/**
	 * 
	 */
	public Cadou() {
		super();
	}
	public double getValoare() {
		return valoare;
	}
	public void setValoare(double valoare) {
		this.valoare = valoare;
	}
	public String getDenumire() {
		return denumire;
	}
	public void setDenumire(String denumire) {
		this.denumire = denumire;
	}
	public Angajat getAngajat() {
		return angajat;
	}
	public void setAngajat(Angajat angajat) {
		this.angajat = angajat;
	}
	@Override
	public String toString() {
		return "Cadou [valoare=" + valoare + ", denumire=" + denumire + ", angajat=" + angajat + "]";
	}
	
	
	
	
}
