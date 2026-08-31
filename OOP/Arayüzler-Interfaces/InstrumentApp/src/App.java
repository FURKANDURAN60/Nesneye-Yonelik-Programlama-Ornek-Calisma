public class App {
    public static void main(String[] args) throws Exception {
        
        Instrument guitar = new Guitar();
        guitar.play();
        //guitar.setChord(); bu kısım çalışmaz çubkü nesneyi interface üzerinden oluşturduk ve interface içerisinde setChord() metodu yok. Bu yüzden bu metodu çağırmak için nesneyi Guitar sınıfından oluşturmalıyız.

        Instrument piano = new Piano();
        piano.play();

    }
}
