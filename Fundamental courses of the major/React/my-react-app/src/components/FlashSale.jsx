import ProductCard from "./ProductCard";
import { products } from "../data/products";

export default function FlashSale() {
  return (
    <section className="flash-sale">
      <div className="flash-header">
        <h2>⚡ FLASH SALE</h2>
        <div className="countdown">Chỉ còn: 02 : 16 : 08</div>
      </div>

      <div className="product-list">
        {products.map((p) => (
          <ProductCard key={p.id} product={p} />
        ))}
      </div>
    </section>
  );
}
