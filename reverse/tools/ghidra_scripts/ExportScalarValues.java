// Export raw scalar values at selected addresses.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class ExportScalarValues extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException("usage: <out.tsv> <address> [address...]");
        }

        File output = new File(args[0]);
        File parent = output.getParentFile();
        if (parent != null) {
            parent.mkdirs();
        }

        Memory memory = currentProgram.getMemory();
        try (PrintWriter writer = new PrintWriter(
                new OutputStreamWriter(new FileOutputStream(output), "UTF-8"))) {
            writer.println("address\traw_le\tfloat32\tint32\tdouble64\tint64");
            for (int i = 1; i < args.length; ++i) {
                Address address = toAddr(args[i]);
                byte[] bytes = new byte[8];
                int count = memory.getBytes(address, bytes);
                if (count != bytes.length) {
                    writer.printf("%s\tREAD_%d_BYTES%n", address, count);
                    continue;
                }

                ByteBuffer buffer = ByteBuffer.wrap(bytes).order(ByteOrder.LITTLE_ENDIAN);
                int int32 = buffer.getInt(0);
                long int64 = buffer.getLong(0);
                float float32 = buffer.getFloat(0);
                double double64 = buffer.getDouble(0);
                StringBuilder raw = new StringBuilder(16);
                for (byte value : bytes) {
                    raw.append(String.format("%02x", value & 0xff));
                }
                writer.printf("%s\t%s\t%.17g\t%d\t%.17g\t%d%n",
                              address, raw, float32, int32, double64, int64);
            }
        }
        println("Wrote " + output.getAbsolutePath());
    }
}
