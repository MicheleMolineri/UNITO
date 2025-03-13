 class Elicottero {
  private int x;
  private int y;
  private int altitude; // 0 <= altitude
  private int speed;    // velocita' orizzontale: 0 <= speed
  private int verticalSpeed;
 private double track;  // angolo direzione: 0<= track<=2pigreco

  /** Costruiamo un elicottero sospeso nelle coordinate (0,0,altitude) con velocita' nulle e angolo di direzione 0 */
  public Elicottero(int x, int y, int a) {
   this.x = x;
   this.y = y;
   this.altitude = a;
   this.speed = 0;
   this.verticalSpeed = 0;
   this.track = 0.0;
  }

  //Metodi get per ogni attributo
  public int getX()             {return x;}
  public int getY()             {return y;}
  public int getAltitude()      {return altitude;}
  public int getSpeed()         {return speed;}
  public int getVerticalSpeed() {return verticalSpeed;}
  public double getTrack()       {return track;}

  /** Metodi set per speed, verticalSpeed e track. Non consento invece di cambiare le coordinate "istantaneamente" */
  public void setSpeed(int speed) {
   assert 0 <= speed: "velocita' non accettabile:" + speed;
   this.speed = speed;
 }


 public void setVerticalSpeed(int verticalSpeed)
  {this.verticalSpeed = verticalSpeed;}

 public void setTrack(double track) {
  assert 0 <= track && track <= 2 * Math.PI: "angolo non accettabile:" + track;
  this.track = track;
 }

  /** Consento di cambiare le coordinate con lo scorrere del tempo */
 public void elapse(double time) {
  int dx = (int) (speed * Math.cos(track) * time); //incremento x
  int dy = (int) (speed * Math.sin(track) * time); //incremento y
  int dz = (int) (verticalSpeed * time);           //incremento z
  x += dx;
  y += dy;
  altitude = Math.max(0, altitude + dz); 
 }
}


public class TestElicottero {
 
public static void main(String[] args) {
//creo un elicottero collocato all'origine del sistema di riferimento
 Elicottero a = new Elicottero(0, 0, 0);
// visualizzo le coordinate dell'elicottero
 System.out.println( "Elicottero a di coordinate" );
 System.out.println("("+a.getX()+","+a.getY()+","+
                   a.getAltitude()+")");
// imposto la velocita' dell'elicottero a 500 km/h
 a.setSpeed(500);
 // imposto la velocita' verticale dell'elicottero a +10 km/h   
 a.setVerticalSpeed(10);
 // imposto la direzione dell'elicottero a nord-nord-est (in radianti)
 a.setTrack((double) (3 * Math.PI / 8));
 System.out.println("velocita'="+a.getSpeed()+" velocita' verticale="
                   + a.getVerticalSpeed()+" angolo="+a.getTrack());
 // faccio trascorrere mezz'ora
 a.elapse(0.5);
 // visualizzo le nuove coordinate: (95,230,5)
 System.out.println("Dopo mezz'ora di volo coordinate: ");
 System.out.println("("+a.getX()+","+a.getY()+","
                    +a.getAltitude()+")");
 }
}

