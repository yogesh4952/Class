using System;
delegate void Notify();

class YoutubeChannel{
  public event Notify VideoUploaded;

  public void UploadVideo(){
    VideoUploaded?.Invoke();
  }
}
class Program{
  static void Subscriber(){
    Console.WriteLine("Sub1 Notified");
  }

  static void Subs2(){
    Console.WriteLine("Sub2 notified");
  }
  public static void Main(string[]args){
     YoutubeChannel channel = new YoutubeChannel();
     
     
     channel.VideoUploaded+=Subs2;
     channel.VideoUploaded+=Subscriber;

     channel.UploadVideo();
  }

}

