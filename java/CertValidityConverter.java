import java.time.LocalDateTime;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.ZoneOffset;

public class CertValidityConverter {

    public static void main(String[] args) {
        String dateString = "2205241818023Z"; // Example input

        // Validate the input string length
        if (dateString.length() != 14) {
            throw new IllegalArgumentException("Invalid date format length. Expected length: 14.");
        }

        // Extract the main part and the fractional second
        String mainPart = dateString.substring(0, 12); // up to ss
        String fractionalSecond = dateString.substring(12, 13); // fractional part

        // Combine the main part and fractional second into a single string compatible with the formatter pattern
        String fullDateString = mainPart + fractionalSecond;

        // Parse the custom date format
        LocalDateTime localDateTime;
        try {
            DateTimeFormatter inputFormatter = DateTimeFormatter.ofPattern("yyMMddHHmmssS");
            localDateTime = LocalDateTime.parse(fullDateString, inputFormatter);
        } catch (DateTimeParseException e) {
            throw new IllegalArgumentException("Invalid date format", e);
        }

        // Convert to ZonedDateTime in UTC
        ZonedDateTime utcDateTime = localDateTime.atZone(ZoneOffset.UTC);

        // Print the UTC date and time
        System.out.println("UTC Date and Time: " + utcDateTime);

        // If you want to format it in a specific way
        DateTimeFormatter outputFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        String formattedUtcDateTime = utcDateTime.format(outputFormatter);
        System.out.println("Formatted UTC Date and Time: " + formattedUtcDateTime);
    }
}
