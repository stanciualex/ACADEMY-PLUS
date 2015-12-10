package com.telenav.parlament.model;

import java.util.Date;

public class Parlamentar extends Angajat {//Mostenire
	private String comisie;
	private String partid;
	/**
	 * @param iD
	 * @param nume
	 * @param adresa
	 * @param dataNasterii
	 * @param salariu
	 * @param comisie
	 * @param partid
	 */
	public Parlamentar(int iD, String nume, String adresa, Date dataNasterii, double salariu, String comisie,
			String partid) {
		super(iD, nume, adresa, dataNasterii, salariu);
		this.comisie = comisie;
		this.partid = partid;
	}
	/**
	 * @param iD
	 * @param nume
	 * @param adresa
	 * @param dataNasterii
	 * @param salariu
	 */
	public Parlamentar() {
		super();
	}
	public String getComisie() {
		return comisie;
	}
	public void setComisie(String comisie) {
		this.comisie = comisie;
	}
	public String getPartid() {
		return partid;
	}
	public void setPartid(String partid) {
		this.partid = partid;
	}
	@Override
	public String toString() {
		return super.toString() + "Parlamentar [comisie=" + comisie + ", partid=" + partid + "]";
	}
	
	
	
}
