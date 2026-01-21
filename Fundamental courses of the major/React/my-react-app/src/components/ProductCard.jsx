function formatPrice(price) {
  return price.toLocaleString("vi-VN") + "đ";
}

export default function ProductCard({ product }) {
  return (
    <div className="product-card">
      <img src={product.image} alt={product.name} />

      <h3>{product.name}</h3>

      <div className="price">
        <span className="new">{formatPrice(product.price)}</span>
        <span className="old">{formatPrice(product.oldPrice)}</span>
        <span className="discount">-{product.discount}%</span>
      </div>

      <div className="remain">🔥 {product.remain}</div>

      <button>Mua ngay</button>
    </div>
  );
}
