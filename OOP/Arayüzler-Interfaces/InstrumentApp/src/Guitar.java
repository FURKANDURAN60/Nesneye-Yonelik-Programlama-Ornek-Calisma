public  class Guitar implements Instrument {
    @Override
    public void play() {
        System.out.println("Guitar is playing");
    }

    public void setChord(){
        System.out.println("Guitar chord is set");
    }

}
