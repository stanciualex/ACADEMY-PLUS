package com.telenav.parlament.model;

public class Pictura extends Cadou{
	private String numePictor;
	private int anulCrearii;
	private boolean original;
	
	public Pictura(double valoare, String denumire, Angajat angajat, String numePictor, int anulCrearii,
			boolean original) {
		super(valoare, denumire, angajat);
		this.numePictor = numePictor;
		this.anulCrearii = anulCrearii;
		this.original = original;
	}
	
	public Pictura() {
		super();
	}

	public String getNumePictor() {
		return numePictor;
	}

	public void setNumePictor(String numePictor) {
		this.numePictor = numePictor;
	}

	public int getAnulCrearii() {
		return anulCrearii;
	}

	public void setAnulCrearii(int anulCrearii) {
		this.anulCrearii = anulCrearii;
	}

	public boolean getOriginal() {
		return original;
	}

	public void setOriginal(boolean original) {
		this.original = original;
	}

	@Override
	public String toString() {
		return "Pictura [numePictor=" + numePictor + ", anulCrearii=" + anulCrearii + ", original=" + original + "]";
	}
	
	
	
}
