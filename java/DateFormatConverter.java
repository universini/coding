import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

public class DateFormatConverter {

    public static void main(String[] args) {
        String dateString = new String("220524181823");

        // Parse the custom date format
        LocalDateTime localDateTime;
        try {
            DateTimeFormatter inputFormatter = DateTimeFormatter.ofPattern("yyMMddHHmmss");
            localDateTime = LocalDateTime.parse(dateString, inputFormatter);
        } catch (DateTimeParseException e) {
            throw new IllegalArgumentException("Invalid date format", e);
        }

        // Format to a more readable string
        DateTimeFormatter outputFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String readableDateString = localDateTime.format(outputFormatter);

        // Print the formatted date string
        System.out.println("Readable Date and Time: " + readableDateString);
    }
}
