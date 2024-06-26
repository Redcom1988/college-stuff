public class Song {
    private String title;
    private String artist;

    public Song(String title, String artist) {
        this.title = title;
        this.artist = artist;
    }

    public String getName() {
        return name;
    }

    public String getArtist() {
        return artist;
    }

    @Override
    public String toString() {
        return title + " by " + artist;
    }
}

public class Node {
    Song song;
    Node next;
    Node prev;

    public Node(Song song) {
        this.song = song;
        this.next = NULL;
        this.prev = NULL;
    }
}